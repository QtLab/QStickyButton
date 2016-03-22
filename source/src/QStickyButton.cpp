/*******************************************************************************
 * Begin of file QStickyButton.cpp
 * Author: Jeroen de Bruijn
 * Created on March 20, 2016, 11:34 AM
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
 * @brief Sticky button that has click and hold capability.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "QStickyButton.h"
#include "ui_QStickyButton.h"

QStickyButton::QStickyButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QStickyButton)
{
    ui->setupUi(this);
    /* Correct the minimum height of the lockbutton. Normally it jumps to 24,
     * which results in an ugly difference to the pushbutton.
     */
    ui->lockStickyButton->setMinimumHeight(23);

    connect(ui->pushStickyButton, &QPushButton::pressed,
            [this]{ QStickyButton::onPushChanged(true); });
    connect(ui->pushStickyButton, &QPushButton::released,
            [this]{ QStickyButton::onPushChanged(false); });
    connect(ui->lockStickyButton, &QPushButton::toggled,
            this, &QStickyButton::onLockToggle);
}

QStickyButton::~QStickyButton()
{
    delete ui;
}

void
QStickyButton::setTitle(const QString& title)
{
    ui->pushStickyButton->setText(title);
}

QString
QStickyButton::title() const
{
    return ui->pushStickyButton->text();
}

void
QStickyButton::onPushChanged(bool pressed)
{
    if(!pressed && ui->lockStickyButton->isChecked()) {
        /* Only uncheck the lockbutton if the pushbutton is released */
        setChecked(pressed);
    } else if (pressed && ui->lockStickyButton->isChecked()) {
        /* Pushbutton is pressed and the lockbutton is checked, so noting
         * happens as the lockbutton is cleared on pushbutton release.
         */
        return;
    } else {
        emit toggled(pressed);
    }
}

void
QStickyButton::onLockToggle(bool checked)
{
    emit toggled(checked);
    setChecked(checked);
}

void
QStickyButton::setChecked(bool pressed)
{
    if (pressed) {
        ui->pushStickyButton->setCheckable(true);
        ui->pushStickyButton->setChecked(true);
        ui->lockStickyButton->setChecked(true);
    } else {
        /* Need to uncheck before setting it uncheckable. Otherwise the button
         * remains checked.
         */
        ui->pushStickyButton->setChecked(false);
        ui->pushStickyButton->setCheckable(false);
        ui->lockStickyButton->setChecked(false);
    }
}

bool
QStickyButton::isChecked() const
{
    return (ui->pushStickyButton->isChecked()                                  |
            ui->lockStickyButton->isChecked());
}
/* End of file QStickyButton.cpp */
