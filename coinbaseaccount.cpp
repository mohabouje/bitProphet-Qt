#include "coinbaseaccount.h"

coinbaseAccount::coinbaseAccount(QObject *parent) {
    mParent = reinterpret_cast<cbApiHandler*>(parent);
    mPtrName = QString("0x%1").arg((quintptr)this, QT_POINTER_SIZE * 2, 16, QChar('0'));
    say("coinbaseAccount Created...");

//    mWalletList.clear();
//    mPayMethods.clear();
}

coinbaseAccount::~coinbaseAccount() {
    say( "coinbaseAccount Fading...");
}

////////////
// Methods
////////////
void coinbaseAccount::say(QString sayThis) {
    mParent->say( "[" +mPtrName+ "] " + sayThis);
}

//int coinbaseAccount::addWallet() {
//    coinbaseWallet *add = new coinbaseWallet(this);
//    mWalletList.append(add);
//    return mWalletList.count()-1; //returns the index of the newly added wallet for reference
//}

//int coinbaseAccount::addPaymentMethod() {
//    coinbasePaymentMethod *add = new coinbasePaymentMethod(this);
//    mPayMethods.append(add);
//    return mPayMethods.count()-1; //returns the index of the newly added ... for reference
//}

//coinbasePaymentMethod* coinbaseAccount::getPaymentMethod(int index) {
//    return mPayMethods.at(index);
//}

//coinbaseWallet* coinbaseAccount::getWallet(int index) {
//    return mWalletList.at(index);
//}

//int coinbaseAccount::getWalletCount() {
//    return mWalletList.count();
//}

//void coinbaseAccount::clearWallets() {
//    mWalletList.clear();
//}


//int coinbaseAccount::getPaymentMethodCount() {
//    return mPayMethods.count();
//}

/////////
// Slots
/////////
