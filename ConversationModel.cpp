#include "ConversationModel.h"

ConversationModel::ConversationModel(QObject *parent) : QAbstractListModel(parent)
{
	_messages.append({"Albert Einstein", "Me", QDateTime::fromString("2015-11-20T06:30:02", Qt::ISODate), "Coucou"});
}

QString ConversationModel::recipient() const
{
	return _recipient;
}

int ConversationModel::rowCount(const QModelIndex &) const
{
	return _messages.count();
}

QVariant ConversationModel::data(const QModelIndex &index, int role) const
{
	if (index.row() < _messages.count()) {
		Message message = _messages[index.row()];
		switch (role) {
		case AuthorRole:
			return message.author;
		case RecipientRole:
			return message.recipient;
		case TimestampRole:
			return message.timestamp.toString(Qt::ISODate);
		case ContentRole:
			return message.content;
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
