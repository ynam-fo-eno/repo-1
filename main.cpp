#include <iostream>

using namespace std;

int main()
{
    double sum=0;
    int itemNumber;

    cout<<"Enter number of items. \n";
    cin>>itemNumber;
    int prices[itemNumber];

    for(int i=0;i<itemNumber;i++)
    {
        cout<<"Enter price of item# "<<(i+1)<<":\t";
        cin>>prices[i];
    }

    cout<<"\n";
    for(int j=0;j<itemNumber;j++)
    {
        sum+=prices[j];
        cout<<"Price of item#"<<(j+1)<<"(without VAT)= sh."<<((double)prices[j])<<"\n";
    }

    cout<<"\n";
    cout<<"Total price= sh."<<sum<<"\nAverage price=Sh."<<(sum/itemNumber)<<"\n";
    cout<<"\n";

    for(int k=0;k<itemNumber;k++)
    {
        cout<<"Price of item#"<<(k+1)<<"(with VAT)= sh."<<((double)prices[k]*1.16)<<"\n";
    }

    cout<<"\n";
    cout<<"Total price(with VAT)= sh."<<(sum*1.16)<<"\nAverage price(with VAT)=Sh."<<((sum/itemNumber)*1.16)<<"\n";
    cout<<"\n";

    cout<<"Write price you wanna search for: \n";
    double desiredPrice;
    cin>>desiredPrice;
    for(int l=0;l<itemNumber;l++)
    {
        if(prices[l]==desiredPrice)
        {
            cout<<"Found!";
            return 0;
        }
        else
        {
            if(l==(itemNumber-1))
            {
                cout<<"Bado\n";
            }
        }
    }

    int listSize=(sizeof(prices)/4);
    cout<<listSize;

}

