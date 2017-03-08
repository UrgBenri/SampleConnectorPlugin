/*
	This file is part of the UrgBenri application.

	Copyright (c) 2016 Mehrez Kristou.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Please contact kristou@hokuyo-aut.jp for more details.

*/

#ifndef SAMPLECONNECTORPLUGIN_H
#define SAMPLECONNECTORPLUGIN_H

#include <QWidget>

#include "ConnectorPluginInterface.h"

namespace Ui {
class SampleConnectorPlugin;
}

class SampleConnectorPlugin : public ConnectorPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(ConnectorPluginInterface)
    Q_PLUGIN_METADATA(IID "org.kristou.UrgBenri.SampleConnectorPlugin")
    PLUGIN_FACTORY(SampleConnectorPlugin)
public:
    explicit SampleConnectorPlugin(QWidget *parent = 0);
    virtual ~SampleConnectorPlugin();

    bool isConnected() { return m_connected;}
    bool isStarted() { return m_started;}
    bool isPaused() { return m_paused;}

    QString pluginName() const {return tr("Sample");}
    QIcon pluginIcon() const {return QIcon(":/SampleConnectorPlugin/tabIcon");}
    QString pluginDescription() const {return tr("Sample Connector plugin");}
    PluginVersion pluginVersion() const {return PluginVersion(1, 0, 0);}
    QString pluginAuthorName() const {return "Mehrez Kristou";}
    QString pluginAuthorContact() const {return "mehrez@kristou.com";}
    int pluginLoadOrder() const {return 99;}
    bool pluginIsExperimental() const { return true; }

    QString pluginLicense() const { return "GPL"; }
    QString pluginLicenseDescription() const { return "GPL"; }

    void loadTranslator(const QString &locale);

    void initialize();

    void saveState(QSettings &settings);
    void restoreState(QSettings &settings);

    bool loadFile(const QString &filename) { return false;}

public slots:
    void start();
    void stop();
    void pause();
    virtual void onLoad(PluginManagerInterface *manager);
    virtual void onUnload();

private:
    Ui::SampleConnectorPlugin *ui;
    bool m_started;
    bool m_connected;
    bool m_paused;

private slots:
    void sample1ButtonClicked();
    void sample2ButtonClicked();
};

#endif // SAMPLECONNECTORPLUGIN_H

