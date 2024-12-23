class Bank {
public:
    vector<long long> accountBalance;
    int accountsCount;
    bool validAccount(int account){
        return account > 0 && account < accountBalance.size();
    }
    Bank(vector<long long>& balance) {
        int accountsCount = balance.size();
        accountBalance.resize(accountsCount + 1, 0);
        for(int i = 0; i < balance.size(); i ++){
            accountBalance[i + 1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(validAccount(account1) && validAccount(account2) && accountBalance[account1] >= money){
            accountBalance[account1] -= money;
            accountBalance[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(validAccount(account)){
            accountBalance[account] += money;
            return true;
        }
        return false;   
    }
    
    bool withdraw(int account, long long money) {
        if(validAccount(account) && accountBalance[account] >= money){
            accountBalance[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */