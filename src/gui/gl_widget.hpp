//
// Created by nagato0614 on 2019/09/23.
//

#ifndef NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_
#define NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_

#include <QtWidgets/QWidget>
#include <QtWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGL/QGL>
#include <QtOpenGL/QGLWidget>
#include <QImage>

namespace nagato {
class GLWidget : public QOpenGLWidget {
 Q_OBJECT

 public:
	explicit GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

	void SetImage(const QImage &image) {
		image_ = image;
		update();
	}

 protected:

	//  OpenGL 初期化
	void initializeGL() override {
		int width = geometry().width();
		int height = geometry().height();
		glViewport( 0, 0, width, height );
		glMatrixMode(GL_PROJECTION);
		glOrtho( -width * 0.5, width * 0.5, -height * 0.5, height * 0.5, -1.0, 1.0 );
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	//  ウィジットリサイズ時のハンドラ
	void resizeGL(int width, int height) override {
		//  ビューポートの指定
		glViewport( 0, 0, width, height );
	}

	//  描画処理
	void paintGL() override {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		QImage gl_image = QGLWidget::convertToGLFormat(image_);
		glDrawPixels(image_.width(),
								 image_.height(),
								 GL_RGBA,
								 GL_UNSIGNED_BYTE,
								 gl_image.bits());
	}

 private:
	QImage image_;
};
}
#endif //NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_
