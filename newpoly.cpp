class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    Polynomial()
    {
        this->degCoeff = new int[6];
        this->capacity = 5;
    }
    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity + 1];
        this->capacity = capacity;
    }
    Polynomial(Polynomial const &p)
    {
        int *newdegCoeff = new int[p.capacity + 1];
        for (int i = 0; i <= p.capacity; i++)
            newdegCoeff[i] = p.degCoeff[i];
        this->degCoeff = newdegCoeff;
        this->capacity = p.capacity;
    }
    void setCoefficient(int degree, int coeff)
    {
        if (degree > capacity)
        {
            int newcapacity = degree;
            int *newdegCoeff = new int[newcapacity + 1];
            for (int i = 0; i <= capacity; i++)
                newdegCoeff[i] = degCoeff[i];
            this->degCoeff = newdegCoeff;
            this->capacity = newcapacity;
            degCoeff[degree] = coeff;
        }
        else
            degCoeff[degree] = coeff;
    }
    Polynomial operator+(Polynomial const &p)
    {
        int newcapacity = max(this->capacity, p.capacity);
        Polynomial p1(newcapacity);
        for (int i = 0; i <= newcapacity; i++)
        {
            if (i <= capacity && i <= p.capacity)
                p1.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
            else if (i <= capacity)
                p1.degCoeff[i] = this->degCoeff[i];
            else
                p1.degCoeff[i] = p.degCoeff[i];
        }
        return p1;
    }
    Polynomial operator-(Polynomial const &p)
    {
        int newcapacity = max(this->capacity, p.capacity);
        Polynomial p1(newcapacity);
        for (int i = 0; i <= newcapacity; i++)
        {
            if (i <= capacity && i <= p.capacity)
                p1.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            else if (i <= capacity)
                p1.degCoeff[i] = this->degCoeff[i];
            else
                p1.degCoeff[i] = -p.degCoeff[i];
        }
        return p1;
    }
    Polynomial operator*(Polynomial const &p)
    {
        int newcapacity = this->capacity + p.capacity;
        Polynomial p1(newcapacity);
        for (int i = 0; i <= this->capacity; i++)
            for (int j = 0; j <= p.capacity; j++)
                p1.degCoeff[i + j] = p1.degCoeff[i + j] + this->degCoeff[i] * p.degCoeff[j];
        return p1;
    }
    void operator=(Polynomial const &p)
    {
        int *newdegCoeff = new int[p.capacity + 1];
        // Copy the contents
        for (int i = 0; i < p.capacity; i++)
            newdegCoeff[i] = p.degCoeff[i];
        this->degCoeff = newdegCoeff;
        this->capacity = p.capacity;
    }
    void print()
    {
        for (int i = 0; i <= this->capacity; i++)
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        cout << endl;
    }
};
