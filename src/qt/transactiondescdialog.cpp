// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/transactiondescdialog.h>
#include <qt/forms/ui_transactiondescdialog.h>

#include <qt/transactiontablemodel.h>

#include <QModelIndex>

TransactionDescDialog::TransactionDescDialog(const QModelIndex &idx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDescDialog),
    m_index(idx)
{
    ui->setupUi(this);
    setWindowTitle(tr("Details for %1").arg(idx.data(TransactionTableModel::TxIDRole).toString()));
    updateDetail();

    if (idx.isValid() && idx.model()) {
        connect(idx.model(), &QAbstractItemModel::dataChanged, this, &TransactionDescDialog::updateDetail);
        connect(idx.model(), &QAbstractItemModel::rowsInserted, this, &TransactionDescDialog::updateDetail);
    }
}

TransactionDescDialog::~TransactionDescDialog()
{
    delete ui;
}

void TransactionDescDialog::updateDetail()
{
    if (m_index.isValid()) {
        QString desc = m_index.data(TransactionTableModel::LongDescriptionRole).toString();
        ui->detailText->setHtml(desc);
    }
}
