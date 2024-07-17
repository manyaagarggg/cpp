class dynamicArray
{
 int * data ;
 int nextIndex;
 int capacity;

public:
dynamicArray (){
    data = new int[5];
    nextIndex =0;
    capacity = 5;
}
void add (int element){
    if(nextIndex==capacity){
     int  *newdata = new int[2*capacity];
     for (int i = 0; i < capacity; i++)
     {
        newdata[i]=data[i];
        /* code */
     }
     delete []data;
      data = newdata;
      capacity *=2;
     
    }
    data[nextIndex]=element;
    nextIndex++;
}
void print(){
    for(int i =0; i<nextIndex;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void add (int i ,int element){
    if(i<nextIndex){
        data[i]=element;
    }
    else if(i==nextIndex){
        add(element);
    }
    return; 
}
};
