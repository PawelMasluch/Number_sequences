#include<iostream>
#include<new>


//using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)

#define FOR(i,a,b) for(int i=a; i<=b; ++i)

#define REPD(i,n) for(int i=n-1; i>=0; --i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


class integerSequence{
	
	private:
		int n; // n >= 0
		int *t;
		
		int computeMinLeadersIndex(){
			
			int candidatesValue = t[0];
			int candidatesMultiplicity = 1;
			
			bool noCandidate = false;
			
			FOR(i,1,n-1){
				
				if( noCandidate == true ){
					
					candidatesValue = t[i];
					candidatesMultiplicity = 1;
				}
				else{
					
					if( t[i] == candidatesValue ){
						++candidatesMultiplicity;
					}
					else{
						
						--candidatesMultiplicity;
						
						if( candidatesMultiplicity == 0 ){
							noCandidate = true;
						}
					}
				}
			}
			
			
			int minLeadersIndex = -1;
			
			int minCandidatesIndex = n;
			candidatesMultiplicity = 0;
			
			REPD(i,n){
				if( t[i] == candidatesValue ){
					++candidatesMultiplicity;
					minCandidatesIndex = i;
				}
			}
			
			
			if( candidatesMultiplicity > n/2 ){
				minLeadersIndex = minCandidatesIndex;
			}
			
			
			return minLeadersIndex;
		}
	
	
	public:
		
		integerSequence(){
			n = 0;
			t = NULL;
		}
		
		
		integerSequence(int n, int defaultValue = 0){
			
			this -> n = n;
			
			this -> t = new int [n];
			
			REP(i,n){
				t[i] = defaultValue;
			}
		}
		
		
		~integerSequence(){
			delete [] t;
		}
		
		
		int getN(){
			return n;
		}
		
		
		int getIthElement(int i){
			return t[i];
		}
		
		
		void setIthElement(int i, int value){
			t[i] = value;
		}
		
		
		void inputAllSequence(){
			
			if( t != NULL ){
				delete [] t;
			}
			
			std::cin >> n;
			
			t = new int [n];
			
			REP(i,n){
				std::cin >> t[i];
			}
		}
		
		
		void outAllSequence(){
			
			REP(i,n){
				std::cout << t[i] << " ";
			}
			
			std::cout << "\n";
		}
		
		
		void outMinLeadersIndex(){
			std::cout << (*this).computeMinLeadersIndex() << std::endl;
		}
};


int main(){
	
	integerSequence S(9,6);
	S.outAllSequence();
	S.outMinLeadersIndex();
	
	S.inputAllSequence();
	S.outAllSequence();
	S.outMinLeadersIndex();

	
	return 0;
}
