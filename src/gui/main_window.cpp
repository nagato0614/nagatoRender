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
    int width = ui_->imageViewer->width();
    int height = ui_->imageViewer->height();;
    //QImageクラスで画像を生成。フォーマットを32ビット画像にする。
    QImage image(width, height, QImage::Format_RGB32);
    Sphere sphere(nullptr, nullptr, {0, 0, 0}, 1);
    PinholeCamera camera({5, 5, 5},
                         {0, 1, 0},
                         {0, 0, 0},
                         45,
                         width,
                         height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
//            Ray ray(Vector3f{2.0f * Float(i) / width - 1.0f,
//                             2.0f * Float(j) / height - 1.0f,
//                             5},
//                    Vector3f{0, 0, -1});
            const Vector3f eye{5, 5, 5};
            const Vector3f center{0, 0, 0};
            const Vector3f up{0, 1, 0};
            const Float fov = 30;
            const Float aspect = (Float) width / height;
            const auto wE = Normalize(eye - center);
            const auto uE = Normalize(Cross(up, wE));
            const auto vE = Cross(wE, uE);

            Ray ray;
            ray.origin_ = eye;
            ray.direction_ = [&]() -> Vector3f {
              Float tf = std::tan(fov * .5);
              Float rpx = 2. * i / width - 1.;
              Float rpy = 2. * j / height - 1.;
              const Vector3f w
              = Normalize(Vector3f({
                  aspect * tf * rpx, tf * rpy, -1.0
              }));
              return uE * w[0] + vE * w[1] + wE * w[2];
            }();
            ray = camera.GeneratePrimaryRay(i, j);
            std::cout << ray.direction_ << std::endl;

            auto hit_info = sphere.Intersect(ray);
            QColor q_color;
            auto tonemap = [](Float v) -> int {
              return std::min(
                  std::max(int(std::pow(v, 1 / 2.2) * 255), 0), 255);
            };
            if (hit_info) {
                Vector3f normal = Normalize(hit_info->GetNormal());
                normal.Clamp(0.0, 1.0);
                q_color.setRgb(
                    255,
                    255,
                    255,
                    255);
            } else {
                q_color.setRgb(0, 0, 0, 255);
            }
            image.setPixelColor(i, j, q_color);
        }
    }
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

