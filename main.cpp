#include <string>
#include <iostream>
#include <image.hpp>
#include <QApplication>
#include "main_window.hpp"


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	nagato::MainWindow w;
	w.show();

	return a.exec();
}