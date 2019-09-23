//
// Created by nagato0614 on 2019/09/23.
//

#include "gl_widget.hpp"

namespace nagato {
GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void GLWidget::SetImage(const QImage &image) {
	image_ = image;
	update();
}

void GLWidget::initializeGL() {
	int width = geometry().width();
	int height = geometry().height();
	glViewport( 0, 0, width, height );
	glMatrixMode(GL_PROJECTION);
	glOrtho( -width * 0.5, width * 0.5, -height * 0.5, height * 0.5, -1.0, 1.0 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void GLWidget::resizeGL(int width, int height) {
	//  ビューポートの指定
	glViewport( 0, 0, width, height );
}

void GLWidget::paintGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	QImage gl_image = QGLWidget::convertToGLFormat(image_);
	glDrawPixels(image_.width(),
							 image_.height(),
							 GL_RGBA,
							 GL_UNSIGNED_BYTE,
							 gl_image.bits());
}

}