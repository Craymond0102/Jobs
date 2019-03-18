//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h serialization class file for assignment 5

#ifndef SERIALIZE_H
#define SERIALIZE_H

using namespace std;

//serializable class
class Serializable
{
	public:
		Serializable(){}
		virtual ~Serializable(){}

		virtual void serialize(ostream & stream) = 0;	//serializes class
		virtual void deserialize(istream & stream) = 0;	//deserializes class
};

#endif
