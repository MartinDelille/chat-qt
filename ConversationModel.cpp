#include <QDebug>

#include "ConversationModel.h"

ConversationModel::ConversationModel(QObject *parent) : QAbstractListModel(parent)
{
	_messages.append({"Albert Einstein", "Me", QDateTime::fromString("2015-11-20T06:30:02", Qt::ISODate), "Coucou"});
	_messages.append({"Me", "Albert Einstein", QDateTime::fromString("2015-11-20T06:30:12", Qt::ISODate), "Ca va?"});
	_messages.append({"Ernest Hemingway", "Me", QDateTime::fromString("2015-11-20T06:30:02", Qt::ISODate), "Hello"});
	_messages.append({"Me", "Ernest Hemingway", QDateTime::fromString("2015-11-20T06:30:12", Qt::ISODate), "Good?"});
}

QString ConversationModel::recipient() const
{
	return _recipient;
}

int ConversationModel::rowCount(const QModelIndex &) const
{
	int count = 0;
	foreach(auto message, _messages) {
		if (recipient() == message.author || recipient() == message.recipient) {
			count++;
		}
	}
	return count;
}

QVariant ConversationModel::data(const QModelIndex &index, int role) const
{
	int i = 0;

	foreach(auto message, _messages) {
		if (recipient() == message.author || recipient() == message.recipient) {
			if (i == index.row()) {
				switch (role) {
				case AuthorRole:
					return message.author;
				case RecipientRole:
					return message.recipient;
				case TimestampRole:
					return message.timestamp.toString(Qt::ISODate);
				case ContentRole:
					qDebug() << message.content;
					return message.content;
				}
			}
			i++;
		}
	}
	return QVariant();
}

QHash<int, QByteArray> ConversationModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[AuthorRole] = "author";
	names[RecipientRole] = "recipient";
	names[TimestampRole] = "timestamp";
	names[ContentRole] = "message";
	return names;
}

void ConversationModel::sendMessage(const QString &recipient, const QString &content)
{
	_messages.append({"Me", recipient, QDateTime::currentDateTime(), content});
}

void ConversationModel::setRecipient(QString recipient)
{
	if (_recipient != recipient) {
		_recipient = recipient;
		emit recipientChanged(_recipient);
	}
}
