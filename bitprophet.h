#ifndef BITPROPHET_H
#define BITPROPHET_H

#include <iostream>
#include <QObject>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include "bpwindow.h"
#include "bpdatabase.h"
#include "coinbaseaccount.h"
#include "cbapihandler.h"
#include "bpsplinechart.h"
#include "cbautospottrader.h"
#include "gdaxapihandler.h"

class bpWindow;
class bpDatabase;
class coinbaseAccount;
class cbApiHandler;
class cbApiResponse;
class bpSplineChart;
class cbAutoSpotTrader;
class gdaxApiHandler;

class bitProphet : public QObject {
    Q_OBJECT    
public:
    explicit bitProphet(QObject *parent);
    ~bitProphet();    
    QString mPtrName;
    QString mState;
    bpDatabase *getDb();
    void setProphetState(QString newState);
    void say(QString sayThis, bool debug=0);
    void addAccountToCoinbaseComboBox(QString accountName);
    //Account Refresh
    bool mAutoRefreshAccount;
    int mAutoRefreshAccountInterval; //all intervals in milliseconds
    //Spot Prices (ie: not gdax market price, coinbase spot price for coinbase buy/sell (stupid, dont use it except for quick reference) )
    bool mAutoCheckSpotPrices;
    int mAutoCheckSpotPricesInterval;
    //GDAX Prices
    bool mAutoCheckGDAXPrices;
    int mAutoCheckGDAXPricesInterval;
    //Simple Trading (non-neural net, simple dumb logix)
    bool mAutoSpotTrade;    
    int mAutoSpotTradeInterval;

    //Simple Trading (GDAX)
    bool mAutoGDAXTrade;
    int mAutoGDAXTradeInterval;
    //////////////
    // Other junk
    bpWindow *mParent;
    void setBtcSpotPrice(cbApiResponse*);
    void setLtcSpotPrice(cbApiResponse*);
    void setEthSpotPrice(cbApiResponse*);
    void setBtcSpotSellPrice(cbApiResponse*);
    void setLtcSpotSellPrice(cbApiResponse*);
    void setEthSpotSellPrice(cbApiResponse*);
    void setBtcSpotBuyPrice(cbApiResponse*);
    void setLtcSpotBuyPrice(cbApiResponse*);
    void setEthSpotBuyPrice(cbApiResponse*);
    void sellAutoBuyId(QString id, QString coin, QString total);
    coinbaseAccount *getHandlerAccount();
    cbApiHandler *getHandler();
    QString findCoinbaseFee(QString dollarAmount);
    void enableAutoSpotTrader();
    void disableAutoSpotTrader();
    void disableGDAXTrader();
    void enableGDAXTrader();
private:
    QList<bpSplineChart*> mSplineChartList;
    bpDatabase *mDb;
    cbApiHandler *mApiHandler;    
public:
    cbAutoSpotTrader *mAutoSpot;
private:
    gdaxApiHandler *mGDAXApiHandler;

signals:

public slots:
void listAccountSlot();
void resetLastSellPriceBtc();
void resetLastSellPriceLtc();
void resetLastSellPriceEth();
};

#endif // BITPROPHET_H
