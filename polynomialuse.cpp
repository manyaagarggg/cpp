class polynomial
{
    int *degCoef;
    int capacity;
    int nextPower;
    public:
    polynomial(int capacity){
        degCoef = new int[5];
        nextPower = 0;
        
    }
    void add (int element){
        if(nextPower==capacity){
             int *newCoef = new int[2*capacity];
             for(int i=0; i<capacity;i++){
                newCoef[i]=degCoef[i];
             }
             delete [] degCoef;
             degCoef = newCoef;
             capacity*= 2;

        }
        degCoef[nextPower]=element;
        nextPower++;
    }
    void print(){
        for(int i=0;i<nextPower;i++){
            cout<<degCoef[i]<<"x"<<i<<" ";

        }
        cout<<endl;
    }
    void add(int element , int i){
        if(i<nextPower){
            degCoef[i]=element;
        }
        else if (i==nextPower){
            add(element);
        }
        return;
    } 
    int max(int i , int j){
        if(i>j){
            return i;
        }
        return j;
    }
    polynomial operator+(polynomial const &p)
    {
        int newcapacity = max(this->capacity, p.capacity);
        polynomial p1( newcapacity);
        for (int i = 0; i <= newcapacity; i++)
        {
            if (i <= capacity && i <= p.capacity)
                p1.degCoef[i] = this->degCoef[i] + p.degCoef[i];
            else if (i <= capacity)
                p1.degCoef[i] = this->degCoef[i];
            else
                p1.degCoef[i] = p.degCoef[i];
        }
        return p1;
    }
};
 