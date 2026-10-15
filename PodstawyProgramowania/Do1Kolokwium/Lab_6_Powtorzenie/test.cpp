int funRekur(int year, float amount, int yearTime) {
    if(yearTime == 0) {
        amount += amount * 0.5;
        return funRekur(year, amount, yearTime + 1) + amount;
    }
    else if(yearTime == 1) {
        return funRekur(year, amount, yearTime + 1) + amount;
    }
    else if(yearTime == 2) {
        amount -= 10;
        return funRekur(year, amount, yearTime + 1) + amount;
    }
    else if(yearTime == 3) {
        amount *= 0.6;
        return funRekur(year - 1, amount, 0) + amount;
    }
    else if(year <= 0 && yearTime == 0) return 0;
    return 0;
}