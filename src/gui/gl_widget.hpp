//
// Created by nagato0614 on 2019/09/23.
//

#ifndef NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_
#define NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_

#include <QtWidgets/QWidget>
#include <QtWidgets/QOpenGLWidget>
#include <QtOpenGL/QGL>
#include <QtOpenGL/QGLWidget>
#include <QImage>

namespace nagato {
class GLWidget : public QOpenGLWidget {
 Q_OBJECT

 public:
	explicit GLWidget(QWidget *parent = nullptr);

	void SetImage(const QImage &image);

 protected:

	//  OpenGL 初期化
	void initializeGL() override;

	//  ウィジットリサイズ時のハンドラ
	void resizeGL(int width, int height) override;

	//  描画処理
	void paintGL() override;

 private:
	QImage image_;
};
}
#endif //NAGATO_RENDER_SRC_GUI_GL_WIDGET_HPP_
