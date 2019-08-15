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
	int width = ui_->imageViewer->width() - 1;
	int height = ui_->imageViewer->height() - 1;
	//QImageクラスで画像を生成。フォーマットを32ビット画像にする。
	QImage image(width, height, QImage::Format_RGB32);
	Sphere sphere(nullptr, nullptr, {0, 0, 0}, 1);
	PinholeCamera camera({5, 5, 5},
											 {0, 1, 0},
											 {0, 0, 0},
											 30,
											 width,
											 height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			Ray ray = camera.GeneratePrimaryRay(i, j);
			auto hit_info = sphere.Intersect(ray);
			QColor q_color;
			auto tonemap = [](Float v) -> int {
				return std::min(
						std::max(int(std::pow(v, 1 / 2.2) * 255), 0), 255);
			};
			if (hit_info) {
				Vector3f normal = Normalize(hit_info->GetNormal());
				normal = (normal + 1.0) * 0.5;
				q_color.setRgb(
						normal[0] * 255,
						normal[1] * 255,
						normal[2] * 255,
						255);
			} else {
				q_color.setRgb(0, 0, 0, 255);
			}
			image.setPixelColor(i, j, q_color);
		}
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

