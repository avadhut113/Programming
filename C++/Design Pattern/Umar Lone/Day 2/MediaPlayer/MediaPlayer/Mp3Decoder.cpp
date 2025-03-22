#include "Mp3Decoder.h"

#include <cctype>


std::string Mp3Decoder::Decode(const std::string& dataStream) {
	std::string decodedStream{} ;
	for(auto ch : dataStream) {
		if(ch == 'e' || ch == 'E' || ch == 'A' || ch == 'a'|| ch == 'I'|| ch == 'i') {
			continue ;
		}
		decodedStream.push_back(ch) ;
	}
	return decodedStream ;

}
