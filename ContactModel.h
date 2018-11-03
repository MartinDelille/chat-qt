#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>

class ContactModel : public QAbstractListModel
{
	Q_OBJECT

	QStringList _contacts;

public:
	explicit ContactModel(QObject *parent = nullptr);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	 QHash<int, QByteArray> roleNames() const override;

signals:

public slots:
};

#endif // CONTACTMODEL_H
