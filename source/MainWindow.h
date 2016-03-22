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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The MainWindow class shows an example implementation of the
 * QSTickyButton with all the capabilities used.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    /***************************************************************************
     * Public Constructors and Destructors
     **************************************************************************/
public:
    /**
     * @brief Default constructor.
     *
     * The system's default constructor.
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief Default destructor.
     *
     * The system's default destructor.
     */
    ~MainWindow();

public slots:
    /**
     * @brief Example user function that is called when the state of the
     * QStickyButton has changed.
     *
     * @param stickyButtonState The current state of the QStickyButton.
     */
    void userFunction(bool stickyButtonState);

private slots:
    /**
     * @brief Set the QStickyButton checked.
     */
    void on_setCheckedTrueButton_clicked();

    /**
     * @brief Set the QStickyButton unchecked.
     */
    void on_setCheckedFalseButton_clicked();

    /**
     * @brief Get the checked state of the QStickyButton.
     */
    void on_isCheckedButton_clicked();

    /**
     * @brief Set the title of the QStickyButton.
     */
    void on_setTitleButton_clicked();

    /**
     * @brief Get the title of the QStickyButton.
     */
    void on_titleButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
