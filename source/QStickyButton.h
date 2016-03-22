/*******************************************************************************
 * Begin of file QStickyButton.h
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
 * @brief Sticky button that has click and hold capability.
 *
 ******************************************************************************/

#ifndef QSTICKYBUTTON_H
#define QSTICKYBUTTON_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <QWidget>

namespace Ui {
class QStickyButton;
}

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The QStickyButton class implements a custom button with click and hold
 * capability.
 *
 * @author Jeroen de Bruijn
 * @version 1.0.0
 *
 * @see @ref button_example_section for the button and example implementation.
 */
class QStickyButton : public QWidget
{
    Q_OBJECT

    /**
     * @brief Title property of the pushbutton.
     *
     * @note This property can be set by adding a `Dynamic Property`, with the
     * `Property Name` set to `title` and the `Property Type` set to `String`,
     * to the QStickyButton.
     */
    Q_PROPERTY(QString title READ title WRITE setTitle)

    /***************************************************************************
     * Public Constructors and Destructors
     **************************************************************************/
public:
    /**
     * @brief Default constructor.
     *
     * The system's default constructor.
     */
    explicit QStickyButton(QWidget *parent = 0);

    /**
     * @brief Default destructor.
     *
     * The system's default destructor.
     */
    ~QStickyButton();

    /***************************************************************************
     * Public Methods
     **************************************************************************/
    /**
     * @brief Set the title of the pushbutton.
     *
     * @param title Title to set.
     */
    void
    setTitle(const QString& title);

    /**
     * @brief Get the title of the pushbutton.
     *
     * @return Title of the pushbutton.
     */
    QString
    title() const;

signals:
    /**
     * @brief Toggled signal for the lockbutton.
     *
     * As the name of the signal probably gives away, this signal is only
     * emitted when the state of the button changes i.e. is toggled from one
     * state to another.
     * @param checked State to set the lockbutton to.
     */
    void
    toggled(bool checked) const;

public slots:
    /**
     * @brief Set the checked state of the sticky button.
     *
     * @param pressed State to set the sticky button to.
     */
    void
    setChecked(bool pressed);

    /**
     * @brief Get the checked or pressed status of the sticky button.
     *
     * @return Current status, checked or being pressed, of the sticky
     * button.
     */
    bool
    isChecked() const;

private slots:
    /**
     * @brief onLockToggle slot for the lockbutton.
     *
     * @param checked The current state of the lockbutton.
     */
    void
    onLockToggle(bool checked);

    /**
     * @brief onPushChanged slot for the pushbutton.
     *
     * @param pressed The current state of the pushbutton.
     */
    void
    onPushChanged(bool pressed);

private:
    Ui::QStickyButton *ui;
};

#endif // QSTICKYBUTTON_H
/* End of file QStickyButton.h */
