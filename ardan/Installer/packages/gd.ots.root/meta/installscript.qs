/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the FOO module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    // call default implementation to actually install README.txt!
    component.createOperations();

    if (systemInfo.productType === "windows") {
        // create start menu shortcut
        component.addOperation("CreateShortcut", 
                            "@TargetDir@/GcuDataLogger.exe",
                            "@StartMenuDir@/CUAS GcuDataLogger.lnk",
                            "workingDirectory=@TargetDir@",
                            "iconPath=@TargetDir@/GcuDataLogger_Icon_White.ico",
                            "iconId=0",
                            "description=Launch Application");
    
        // create start menu uninstall shortcut
        component.addOperation("CreateShortcut", 
                            "@TargetDir@/maintenancetool.exe",
                            "@StartMenuDir@/CUAS GcuDataLogger Uninstall.lnk",
                            "workingDirectory=@TargetDir@",
                            "iconPath=@TargetDir@/GcuDataLogger_Icon_White.ico",
                            "iconId=0",
                            "description=Uninstall Application");
        
        // create desktop shortcut
        component.addOperation("CreateShortcut", 
                            "@TargetDir@/GcuDataLogger.exe",                            // target
                            "@DesktopDir@/CUAS GcuDataLogger.lnk",                      // link-path
                            "workingDirectory=@TargetDir@",                             // working-dir
                            "iconPath=@TargetDir@/GcuDataLogger_Icon_White.ico",
                            "iconId=0",
                            "description=Launch Application");                          // description
    }
}
