#include <QDebug>

#include "ContactModel.h"

ContactModel::ContactModel(QObject *parent) : QAbstractListModel(parent)
{
	_contacts.append({"Albert Einstein", "Ernest Hemingway", "Hans Gude"});
}

int ContactModel::rowCount(const QModelIndex &parent) const
{
	qDebug() << "rowCount" <<  _contacts.count();
	return _contacts.count();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
	qDebug() << "data:" << index.row() << role;
	if (index.row() < _contacts.count()) {
		return _contacts[index.row()];
	}
	return QVariant();
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[Qt::UserRole] = "name";
	return names;
}
