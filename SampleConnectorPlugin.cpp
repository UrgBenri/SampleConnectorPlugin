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

#include "SampleConnectorPlugin.h"
#include "ui_SampleConnectorPlugin.h"

#include "SampleDataConverter.h"

SampleConnectorPlugin::SampleConnectorPlugin(QWidget *parent)
    : ConnectorPluginInterface(parent)
    , ui(new Ui::SampleConnectorPlugin)
    , m_started(false)
    , m_connected(true)
    , m_paused(false)
{
    initialize();
}

SampleConnectorPlugin::~SampleConnectorPlugin()
{
    delete ui;
}

void SampleConnectorPlugin::initialize()
{
    ui->setupUi(this);

    connect(ui->sample1Button, &QAbstractButton::clicked,
            this, &SampleConnectorPlugin::sample1ButtonClicked);

    connect(ui->sample2Button, &QAbstractButton::clicked,
            this, &SampleConnectorPlugin::sample2ButtonClicked);
}

void SampleConnectorPlugin::start()
{
    m_started = true;
    m_paused = false;
    emit started();
}

void SampleConnectorPlugin::stop()
{
    m_started = false;
    m_paused = false;
    emit stopped();
}

void SampleConnectorPlugin::pause()
{
    m_started = false;
    m_paused = true;
    emit paused();
}

void SampleConnectorPlugin::onLoad(PluginManagerInterface *manager)
{

}

void SampleConnectorPlugin::onUnload()
{

}

void SampleConnectorPlugin::sample1ButtonClicked()
{
    QVector<QVector<long > > steps;
    for(int i = 0; i < 1081; ++i){
        QVector<long > echos;
        echos << 1000;
        steps << echos;
    }

    PluginDataStructure data;
    data.ranges = steps;
    data.timestamp = 1234;
    data.converter = QSharedPointer<DataConverterInterface>(new SampleDataConverter(540, 1440, 0, 1080, 1));
    emit measurementDataReady(data);
}

void SampleConnectorPlugin::sample2ButtonClicked()
{
    QVector<QVector<long > > steps;
    for(int i = 0; i < 1081; ++i){
        QVector<long > echos;
        echos << 5000;
        steps << echos;
    }

    PluginDataStructure data;
    data.ranges = steps;
    data.timestamp = 1234;
    data.converter = QSharedPointer<DataConverterInterface>(new SampleDataConverter(540, 1440, 0, 1080, 1));
    emit measurementDataReady(data);
}


void SampleConnectorPlugin::saveState(QSettings &settings)
{
}

void SampleConnectorPlugin::restoreState(QSettings &settings)
{
}


void SampleConnectorPlugin::loadTranslator(const QString &locale)
{
}

