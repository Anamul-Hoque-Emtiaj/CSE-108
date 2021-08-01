#include<iostream>
#include<cstring>
using namespace std;

class Cricketer
{
    int matchPlayed,age;
    char name[20];
public:
    Cricketer(char *s,int a,int m)
    {
        strcpy(name,s);
        age=a;
        matchPlayed=m;
    }

    char *getName()
    {
        return name;
    }
    int playedMatch()
    {
        return matchPlayed;
    }
};

class Batsman: virtual public Cricketer
{
    int runScored;
public:
    Batsman(char *s,int age,int matchPlayed,int runScorred): Cricketer(s, age, matchPlayed)
    {
        runScored=runScorred;
    }
    double computeBattingAverage()
    {
        return (1.00*runScored)/(playedMatch()*1.00);
    }
};

class Bowler: virtual public Cricketer
{
    int wicketsTaken,runGiven;
public:
    Bowler(char *s,int age,int matchPlayed, int givenRun): Cricketer(s, age, matchPlayed)
    {
        runGiven= givenRun;
    }
    double computeWicketAverage()
    {
        return (1.00*wicketsTaken)/(playedMatch()*1.00);
    }
    double computeAverageRunPerMatch()
    {
        return (1.00*runGiven)/(playedMatch()*1.00);
    }
};

class AllRounder: public Batsman, public Bowler
{
public:
    AllRounder(char *s,int age,int matchPlayed,int runScorred,int runGiven): Batsman(s, age, matchPlayed, runScorred), Bowler(s, age, matchPlayed,runGiven),Cricketer(s, age, matchPlayed)

    {

    }
};

int main()
{
    AllRounder a("Shakib",28,200,5000,400);
    cout<<a.getName()<<" "<<a.computeAverageRunPerMatch()<<" "<<a.computeBattingAverage()<<endl;
    return 0;
}
