/*******************************************************************************
 * Begin of file MainWindow.h
 * Author: Jeroen de Bruijn
 * Created on March 19, 2016, 04:53 PM
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 *
 * Copyright (c) 2016  Jeroen de Bruijn  <vidavidorra4pub@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Example implementation of the QStickyButton.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->stickyButton, &QStickyButton::toggled,
                this, &MainWindow::userFunction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::userFunction(bool stickyButtonState)
{
    QString boolText = stickyButtonState ? "true" : "false";
    ui->buttonStateLine->setText(boolText);
}

void MainWindow::on_setCheckedTrueButton_clicked()
{
    ui->stickyButton->setChecked(true);
}

void MainWindow::on_setCheckedFalseButton_clicked()
{
    ui->stickyButton->setChecked(false);
}

void MainWindow::on_isCheckedButton_clicked()
{
    QString boolText = ui->stickyButton->isChecked() ? "true" : "false";
    ui->isCheckedLine->setText(boolText);
}

void MainWindow::on_setTitleButton_clicked()
{
    ui->stickyButton->setTitle(ui->setTitleLineEdit->text());
}

void MainWindow::on_titleButton_clicked()
{
    ui->titleLine->setText(ui->stickyButton->title());
}
/* End of file MainWindow.h */
