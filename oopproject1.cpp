#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
class Flight              //Flight Class
{
    private:
    string FlightNumber;
    string DepartureCity;
    string ArrivalCity;
    string DepartureTime;
    string ArrivalTime;
    string DepartureDate;
    int TotalSeats;
    int AvailableSeats;
    Flight *Ptr;
    int ArraySize;

    public:
    Flight();
    Flight(const Flight &obj);
    Flight(string fn,string dc,string ac,string dt,string at,string dd,int ts,int as);
    ~Flight();
            //Getter Functions
    string GetFlightNumber()const;
    string GetDepartureCity()const;
    string GetArrivalCity()const;
    string GetDepartureTime()const;
    string GetArrivalTime()const;
    string GetDepartureDate()const;
    int GetTotalSeats()const;
    int GetAvailableSeats()const;
        //Setter Functions
    void SetFlightNumber(string fn);
    void SetDepartureCity(string dc);
    void SetArrivalCity(string ac);
    void SetDepartureTime(string dt);
    void SetArrivalTime(string at);
    void SetDepartureDate(string dd);
    void SetTotalSeats(int ts);
    void SetAvailableSeats(int as);

    Flight& operator [](int &index);
    virtual void UpdateFlightInfo(int,int);
};
Flight :: Flight(){
    //body of default constructor
    FlightNumber="0001";
    DepartureCity="Lahore";
    ArrivalCity="Multan";
    DepartureTime="3:04";
    ArrivalTime="5:00";
    DepartureDate="1-1-2-25";
    TotalSeats=100;
    AvailableSeats=50;

}
Flight :: Flight(const Flight &obj){
    //body of copy constructor
    FlightNumber=obj.FlightNumber;
    DepartureCity=obj.DepartureCity;
    ArrivalCity=obj.ArrivalCity;
    DepartureTime=obj.DepartureTime;
    ArrivalTime=obj.ArrivalTime;
    DepartureDate=obj.DepartureDate;
    TotalSeats=obj.TotalSeats;
    AvailableSeats=obj.AvailableSeats;
    
}
Flight :: Flight(string fn,string dc,string ac,string dt,string at,string dd,int ts,int as){
    //body of parametrized constructor
    FlightNumber=fn;
    DepartureCity=dc;
    ArrivalCity=ac;
    DepartureTime=dt;
    ArrivalTime=at;
    DepartureDate=dd;
    TotalSeats=ts;
    AvailableSeats=as;
}
Flight :: ~Flight(){
    delete Ptr;
}
            //definition of getter functions
string Flight :: GetFlightNumber() const {
    return FlightNumber;
}
string Flight :: GetDepartureCity() const {
    return DepartureCity;
}
string Flight :: GetArrivalCity() const {
    return ArrivalCity;
}
string Flight :: GetDepartureTime() const {
    return DepartureTime;
}
string Flight :: GetArrivalTime() const {
    return ArrivalTime;
}
string Flight :: GetDepartureDate() const {
    return DepartureDate;
}
int Flight :: GetTotalSeats() const {
    return TotalSeats;
}
int Flight :: GetAvailableSeats() const {
    return AvailableSeats;
}

            //definition of setter functions
void Flight :: SetFlightNumber(string fn){
FlightNumber=fn;
}
void Flight :: SetDepartureCity(string dc){
DepartureCity=dc;
}
void Flight :: SetArrivalCity(string ac){
ArrivalCity=ac;
}
void Flight :: SetDepartureTime(string dt){
DepartureTime=dt;
}
void Flight :: SetArrivalTime(string at){
ArrivalTime=at;
}
void Flight :: SetDepartureDate(string dd){
DepartureDate=dd;
}
void Flight :: SetTotalSeats(int ts){
TotalSeats=ts;
}
void Flight :: SetAvailableSeats(int as){
AvailableSeats=as;
}
Flight &Flight :: operator [](int &index){
    //[] overloading code goes here
if (index < 0 || index >= ArraySize){
cout<<"Invalid Index!!! Please apni oqat ma rhain\n";
}
else{
return Ptr[index];
}
}
void Flight :: UpdateFlightInfo(int,int){
//code of function named UpdateFlightInfo goes here
ifstream fin("myfile.txt",ios::app);
if(fin.is_open()){

}
cout<<"Enter the new flight number:";
cin>>FlightNumber;
cout<<"Enter the departure city of the flight:";
cin>>DepartureCity;
cout<<"Enter the new arrival city of the flight:";
cin>>ArrivalCity;
cout<<"Enter the new departure time of the flight:";
cin>>DepartureTime;
cout<<"Enter the new arrival time of the flight:";
cin>>ArrivalTime;
cout<<"Enter the new departure date of the flight:";
cin>>DepartureDate;
cout<<"Enter the new total number of seats of the flight:";
cin>>TotalSeats;
}

class InternationalFlight : public Flight              //InternationalFlight Class
{
    private:

    public:
};

class DomesticFlight : public Flight            //DomesticFlight Class
{
    private:
    
     
    public:
};

class Passenger              //Passenger Class
{
    private:
    string Name;
    int Age;
    string ReferenceNo;

    public:
    Passenger();
    Passenger(string n,int a);
    Passenger(const Passenger &obj);
    Passenger& operator=(const Passenger &obj);
    string GenerateBookingRef();
    string GetName()const;
    int GetAge()const;
    string GetReferenceNo()const;
    void SetName(string n);
    void SetAge(int a);
    void SetReferenceNo(string rn);

};
Passenger :: Passenger(){
    //code of default constructor
    //parametrize ko kr tu
    Name="Asif";
    Age=19;
    ReferenceNo=1;
}
Passenger :: Passenger(string n,int a){
    //code of Parametrized constructor
    Name=n;
    Age=a;
    //oy dono ma nhi ha
}
Passenger :: Passenger(const Passenger &obj){
    //code of copy constructor
    Name=obj.Name;
    Age=obj.Age;
    ReferenceNo=obj.ReferenceNo;
}
Passenger& Passenger :: operator=(const Passenger &obj){
    //body of = overloading
     if (this != &obj) {  // Check for self-assignment
            Name = obj.Name;
            Age=obj.Age;
            ReferenceNo=obj.ReferenceNo;
            
        }
        return *this;
}
string Passenger :: GenerateBookingRef(){
    //code goes here
}
        //definitions of getter functions
string Passenger :: GetName() const {
    return Name;
}
int Passenger :: GetAge() const {
    return Age;
}
string Passenger :: GetReferenceNo() const {
    return ReferenceNo;
}
        //definitions of setter functions
void Passenger :: SetName(string n){

    Name=n;
}
void Passenger::SetAge(int a) {
    Age=a;
}
void Passenger :: SetReferenceNo(string rn){
    ReferenceNo=rn;
}


class Reservation              //Reservation Class
{
    private:
    Flight *flight;
    Passenger *passenger;
    bool status;
    int flightcount;
        

    public:
    Reservation();
    Reservation(Flight *f,Passenger *p, bool s,int fc);
    Reservation(const Reservation &obj);
    ~Reservation();
    Reservation& operator=(const Reservation &obj);
    void UpdateStatus(bool s);
    bool GetStatus()const;
    void SetStatus(bool s);
};
Reservation :: Reservation(){

}
Reservation :: Reservation(Flight *f,Passenger *p, bool s, int fc){
        flight=f;
        passenger=p;
        status=s;
        flightcount=fc;
}
Reservation :: Reservation(const Reservation &obj){
    
}
Reservation :: ~Reservation(){
    delete flight;
    delete passenger;
}
Reservation& Reservation :: operator=(const Reservation &obj){
//= overloading
 if (this != &obj) {  
        // Check for self-assignment
        flight = obj.flight;
        flightcount=obj.flightcount;
        passenger=obj.passenger;
        status=obj.status;
        }
        return *this;
}
void Reservation :: UpdateStatus(bool s){
status=s;
if(status==true){
    cout<<"This reservation is not available!\n";
}
else{
    cout<<"This reservation is available!\n";
}
}
bool Reservation :: GetStatus()const{
return status;
}
void Reservation :: SetStatus(bool s){
status=s;
}

class Ticket              //Ticket Class
{
    private:
    string TicketId;
    Passenger *passenger;
    Flight *flight;
    string SeatNumber;
    double TicketPrice;

    public:
    Ticket();
    Ticket(string i, Passenger *p, Flight *f, string sn, double pr);
    ~Ticket();
    void ManageTicketInfo();
    string GetTicketId();
    string GetTicketSeatNo();
    double GetTicketPrice();
    void SetTicketId(string i);
    void SetTicketSeatNo(string sn);
    void SetTicketPrice(double p);
    
};
Ticket :: Ticket(){
TicketId="1";
SeatNumber="#1";
TicketPrice=3454534;
}
Ticket :: Ticket(string i, Passenger *p, Flight *f, string sn, double pr){
    TicketId=i;
    passenger=p;
    flight=f;
    SeatNumber=sn;
    TicketPrice=pr;
    
}
Ticket :: ~Ticket(){
    delete passenger;
    delete flight;

}
void Ticket :: ManageTicketInfo(){
    //code goes here
    cout<<"Enter the new ticket id:";
    cin>>TicketId;
}
string Ticket :: GetTicketId(){
    return TicketId;
}
string Ticket :: GetTicketSeatNo(){
    return TicketId;
}
double Ticket :: GetTicketPrice(){
    return TicketPrice;
}
void Ticket :: SetTicketId(string i){
TicketId=i;
}
void Ticket :: SetTicketSeatNo(string sn){
SeatNumber=sn;
}
void Ticket :: SetTicketPrice(double pr){
TicketPrice=pr;
}

class FlightManager              //FlightManager Class
{
    private:
    Flight *flight;
    Reservation *reservation;
    int FlightsCount;
    int ReservationsCount;
    public:
    FlightManager();
    ~FlightManager();
    void AddFlight(Flight *flight);
    void RemoveFlight(string n);
    void SearchFlights(string);
    void UpdateFlightInfo(string n, int,int);
    void DisplayAvailableFlights();
    int GetfFlightsCount();
    int GetReservationsCount();
    void SetFlightsCount(int fc);
    void SetReservationsCount(int rc);
};
FlightManager :: FlightManager(){
FlightsCount=100;
ReservationsCount=20;
}
FlightManager :: ~FlightManager(){
    delete flight;
    delete reservation;
}
void FlightManager :: AddFlight(Flight *flight){
    //code goes here
}
void FlightManager ::RemoveFlight(string n){
    //code goes here
}
void FlightManager :: SearchFlights(string n){
    //code goes here
}
void FlightManager :: UpdateFlightInfo(string n,int,int){
    //code goes here
}

void FlightManager :: DisplayAvailableFlights(){
    //code goes here
}
int FlightManager :: GetfFlightsCount(){
    return FlightsCount;
}
int FlightManager :: GetReservationsCount(){
    return ReservationsCount;
}
    void FlightManager :: SetFlightsCount(int fc){
        FlightsCount=fc;
    }
    void FlightManager :: SetReservationsCount(int rc){
        ReservationsCount=rc;
    }



class ReservationManager              //ReservationManager Class
{
    private:
    Reservation *reservation;
    int ReservationCount;

    public:
    ReservationManager();
    ~ReservationManager();
    void AddReservation(string,Reservation*,string);
    void SearchReservation(string);
    void CancelReservation(string);
    int GetReservationCount();
    void SetReservationCount(int c);
};
ReservationManager :: ReservationManager(){
ReservationCount=10;
}
ReservationManager :: ~ReservationManager(){
    delete reservation;
}
void AddReservation(string,Reservation*,string){
    //code goes here
}
void ReservationManager :: SearchReservation(string){
    //code goes here
}
void ReservationManager :: CancelReservation(string){
    //code goes here
}
int ReservationManager :: GetReservationCount(){
    return ReservationCount;
}
void ReservationManager :: SetReservationCount(int c){
    ReservationCount=c;
}
int main(){


    return 0;
}