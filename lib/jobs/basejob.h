/******************************************************************************
 * Copyright (C) 2015 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef QMATRIXCLIENT_BASEJOB_H
#define QMATRIXCLIENT_BASEJOB_H

#include <KCoreAddons/KJob>
#include <QtCore/QJsonDocument>

class QNetworkReply;

namespace QMatrixClient
{
    class Connection;
    
    class BaseJob: public KJob
    {
            Q_OBJECT
        public:
            BaseJob(Connection* connection);
            virtual ~BaseJob();
            
        protected:
            Connection* connection() const;
            
            QNetworkReply* get(const QString& path) const;
            QNetworkReply* put(const QString& path, const QJsonDocument& data) const;
            QNetworkReply* post(const QString& path, const QJsonDocument& data) const;
            
            void fail( int errorCode, QString errorString );
            
        private:
            class Private;
            Private* d;
    };
}

#endif // QMATRIXCLIENT_BASEJOB_H