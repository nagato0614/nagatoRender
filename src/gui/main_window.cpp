//
// Created by nagato0614 on 2019-08-09.
//

#include "main_window.hpp"
#include <iostream>
#include <QtWidgets/QGraphicsPixmapItem>
#include <cmath>

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
	int width = 100, height = 50;
	//QImageクラスで画像を生成。フォーマットを32ビット画像にする。
	QImage image(width, height, QImage::Format_ARGB32);

	//ix, iyの2重ルーブで、全ての画素の色を設定する。
	for (int ix = 0; ix < width; ix++) {
		for (int iy = 0; iy < height; iy++) {
			//色の値を決める。0〜255の範囲内に収まるようにする。
			int red = 120 * (1 + sin(ix * 0.5));
			int green = 120 * (1 + cos(iy * 0.5));
			int blue = 120 * (1 + sin(iy * 0.2));
			//透明度の設定
			int alpha = 255;
			//Qtの色のクラスに色を設定する。
			QColor color;
			color.setRgb(red, green, blue, alpha);
			//座標(ix, iy)の画素の色を設定する。
			image.setPixelColor(ix, iy, color);
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

