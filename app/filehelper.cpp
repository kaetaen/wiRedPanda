﻿// Copyright 2015 - 2021, GIBIS-Unifesp and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include <iostream>
#include <QDebug>
#include <QDir>

#include "filehelper.h"
#include "globalproperties.h"
#include "icnotfoundexception.h"

QFileInfo FileHelper::findICFile(const QString &fname, const QString &parentFile)
{
    qDebug() << "Loading file: " << fname << ", parentFile: " << parentFile;
    QFileInfo fileInfo(fname);
    QString myFile = fileInfo.fileName();
    if (!fileInfo.isFile()) {
        fileInfo.setFile(QDir::current(), fileInfo.fileName());
        if (!fileInfo.isFile()) {
            fileInfo.setFile(QFileInfo(parentFile).absoluteDir(), myFile);
            if (!fileInfo.isFile()) {
                QFileInfo currentFile(GlobalProperties::currentFile);
                fileInfo.setFile(currentFile.absoluteDir(), myFile);
                if (!fileInfo.isFile()) {
                    qDebug() << "Searching subdir boxes: " << QString::fromStdString(currentFile.absolutePath().toStdString()) << "/boxes";
                    QDir subdir(currentFile.absolutePath());
                    subdir.cdUp();
                    fileInfo.setFile(QDir(subdir.absolutePath() + "/boxes"), myFile);
                    qDebug() << "Searching sibling subdir boxes: " << QString::fromStdString(subdir.absolutePath().toStdString()) << "/boxes";
                    if (!fileInfo.isFile()) {
                        std::cerr << "Error: This file does not exists: " << fname.toStdString() << std::endl;
                        throw(ICNotFoundException(QString(tr("IC linked file \"%1\" could not be found!\n"
                                                             "Do you want to find this file?"))
                                                      .arg(fname)
                                                      .toStdString(),
                                                  nullptr));
                    }
                }
            }
        }
    }
    return fileInfo;
}

QFileInfo FileHelper::findSkinFile(const QString &fname)
{
    qDebug() << "Loading file: " << fname;
    QFileInfo fileInfo(fname);
    QString myFile = fileInfo.fileName();
    if (!fileInfo.isFile()) {
        fileInfo.setFile(QDir::current(), fileInfo.fileName());
        if (!fileInfo.isFile()) {
            QFileInfo currentFile(GlobalProperties::currentFile);
            fileInfo.setFile(currentFile.absoluteDir(), myFile);
            if (!fileInfo.isFile()) {
                qDebug() << "Searching subdir skins: " << QString::fromStdString(currentFile.absolutePath().toStdString()) << "/skins";
                fileInfo.setFile(QDir(currentFile.absolutePath() + "/skins"), myFile);
                if (!fileInfo.isFile()) {
                    fileInfo.setFile(QDir(currentFile.absolutePath() + "/skins"), myFile);
                    if (!fileInfo.isFile()) {
                        std::cerr << "Error: This file does not exists: " << fname.toStdString() << std::endl;
                    }
                }
            }
        }
    }
    qDebug() << "FileInfo found: " << QString::fromStdString(fileInfo.absoluteFilePath().toStdString());
    return fileInfo;
}

void FileHelper::verifyRecursion(const QString &fname)
{
    Q_UNUSED(fname);
    // TODO: BoxFileHelper::verifyRecursion
    //  std::string msg = "Oh no! I'm my own parent.\nSomething is not ok...";
    //  if( !parentFile.isEmpty( ) && ( fname == parentFile ) ) {
    //    throw( std::runtime_error( msg ) );
    //  }
    //  for( Box *box = parentBox; box != nullptr; box = box->getParentBox( ) ) {
    ////    qDebug( ) << "File: " << box->getFile( );
    //    if( box->getFile( ) == fname ) {
    //      throw( std::runtime_error( msg ) );
    //    }
    //  }
}
