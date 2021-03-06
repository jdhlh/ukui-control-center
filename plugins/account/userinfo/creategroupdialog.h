/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2020 KYLINOS Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef CREATEGROUPDIALOG_H
#define CREATEGROUPDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QPainterPath>
#include <QCheckBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QListWidget>

class UserInfo;
class ChangeGroupDialog;
namespace Ui {
class CreateGroupDialog;
}

class CreateGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroupDialog(QWidget *parent = nullptr);
    ~CreateGroupDialog();

public:
    void limitInput();
    void getUsersList();
    void refreshCertainBtnStatus();
    QPushButton * certainBtnComponent();
    QLineEdit * lineNameComponent();
    QLineEdit * lineIdComponent();
    QListWidget * listWidgetComponent();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::CreateGroupDialog *ui;
    ChangeGroupDialog *cgDialog = nullptr;
    bool _nameHasModified;
    bool _idHasModified;
    bool _boxModified;

    void setupInit();
    void signalsBind();
};

#endif // CREATEGROUPDIALOG_H
