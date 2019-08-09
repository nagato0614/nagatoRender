//
// Created by nagato0614 on 2019-08-09.
//

#ifndef NAGATO_RENDER_SRC_GUI_MAIN_WINDOW_HPP_
#define NAGATO_RENDER_SRC_GUI_MAIN_WINDOW_HPP_

#include <QtWidgets/QMainWindow>
#include <ui_mainwindow.h>

namespace nagato {
class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
	explicit MainWindow(QWidget *parent = nullptr);

	~MainWindow() override;

 private slots :

	void Render();

	void Stop();

 private:

	Ui::MainWindow *ui_;
	QGraphicsScene graphics_scene_;
};
}
#endif //NAGATO_RENDER_SRC_GUI_MAIN_WINDOW_HPP_
