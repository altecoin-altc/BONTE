// Copyright (c) 2019 The Altecoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REQUESTDIALOG_H
#define REQUESTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include "walletmodel.h"
#include "qt/altecoin/snackbar.h"

class WalletModel;
class AltecoinGUI;

namespace Ui {
class RequestDialog;
}

class RequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RequestDialog(QWidget *parent = nullptr);
    ~RequestDialog();

    void setWalletModel(WalletModel *model);
    void setPaymentRequest(bool isPaymentRequest);
    void showEvent(QShowEvent *event) override;
    int res = -1;

private slots:
    void onNextClicked();
    void onCopyClicked();
    void onCopyUriClicked();

private:
    Ui::RequestDialog *ui;
    int pos = 0;
    bool isPaymentRequest = true;
    WalletModel *walletModel;
    SnackBar *snackBar = nullptr;
    // Cached last address
    SendCoinsRecipient *info = nullptr;

    QPixmap *qrImage = nullptr;

    void updateQr(QString str);
    void inform(QString text);
};

#endif // REQUESTDIALOG_H
