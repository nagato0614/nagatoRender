//
// Created by nagato0614 on 2019-08-09.
//

#include "main_window.hpp"
#include <iostream>
#include <QtWidgets/QGraphicsPixmapItem>
#include <cmath>
#include "pinhole_camera.hpp"
#include "sphere.hpp"
#include "hit_info.hpp"
#include "scene.hpp"
#include "linear_intersector.hpp"

namespace nagato {
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    connect(ui_->renderButton, SIGNAL(clicked()), this, SLOT(Render()));
    connect(ui_->stopButton, SIGNAL(clicked()), this, SLOT(Stop()));
}
MainWindow::~MainWindow() {
    delete ui_;
}
void MainWindow::Render() {
    //画像サイズを設定
    int width = ui_->imageViewer->width() - 5;
    int height = ui_->imageViewer->height() - 5;
    //QImageクラスで画像を生成。フォーマットを32ビット画像にする。
    QImage image(width, height, QImage::Format_RGB32);

    Scene scene(std::make_unique<LinearIntersector>());
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(-0.5, 1, 0), 1));
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(0.5, 1, 0), 1));
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(0, -901, 0), 900));

    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(1e5 + 1, 40.8, 81.6), 1e5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(-1e5 + 99, 40.8, 81.6), 1e5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, 40.8, 1e5), 1e5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, 1e5, 81.6), 1e5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, -1e5 + 81.6, 81.6), 1e5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(27, 16.5, 47), 16.5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(73, 16.5, 78), 16.5));
    scene.AddObject(
        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, 681.6 - .27, 81.6), 600));
    scene.Build();
    std::cout << "objects : " << scene.GetObjects().size() << std::endl;

    // Camera parameters
    const Vector3f eye(50, 52, 295.6);
    const Vector3f center = eye + Vector3f(0, -0.042612, -1);
    const Vector3f up(0, 1, 0);

//    const Vector3f eye(0, 1, 5);
//    const Vector3f up(0, 1, 0);
//    const Vector3f center(0, 1, 0);

    PinholeCamera camera(eye,
                         up,
                         center,
                         30,
                         width,
                         height);

#pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < width * height; i++) {
        const int x = i % width;
        const int y = height - 1 - i / width;
        Ray ray = camera.GeneratePrimaryRay(x, y);
        auto hit_info = scene.Intersect(ray);
        QColor q_color;
        auto tonemap = [](Float v) -> int {
          return std::min(
              std::max(int(std::pow(v, 1 / 2.2) * 255), 0), 255);
        };
        if (hit_info) {
            Vector3f normal = Normalize(hit_info->GetNormal());
            normal = (normal + 1.0) * 0.5;
            q_color.setRgb(
                normal[0] * 255.0,
                normal[1] * 255.0,
                normal[2] * 255.0,
                255);
        } else {
            q_color.setRgb(151, 199, 199, 255);
        }
        image.setPixelColor(x, height - 1 - y, q_color);
    }
    image.save("test.png");
    QGraphicsPixmapItem *image_item
        = new QGraphicsPixmapItem(QPixmap::fromImage(image));

    graphics_scene_.addItem(image_item);
    ui_->imageViewer->setScene(&graphics_scene_);
    std::cout << "render" << std::endl;
}
void MainWindow::Stop() {
    std::cout << "stop" << std::endl;
}
}

