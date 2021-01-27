#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <map>

using namespace std;

vector <string> split(string& to_split, char delimiter)
{
	vector <string> split_vec;
	size_t delim_ind = 0;
	size_t old_ind = 0;
	delim_ind = to_split.find(delimiter, old_ind);
	while (delim_ind != string::npos)
	{
		split_vec.push_back(to_split.substr(old_ind, (delim_ind - old_ind)));
		old_ind = delim_ind + 1;
		delim_ind = to_split.find(delimiter, old_ind);
	}
	split_vec.push_back(to_split.substr(old_ind, (to_split.length() - old_ind)));
	return split_vec;
}

int main()
{
	list<std::string> SchreibenSieeineFunktionumdieTextdateipersonencsvohneweitereVerarbeitungineinenContainermitStringseinzulesen;
	try {

		ifstream input;

		input.open("C:\\Users\\minem\\Desktop\\FH\\OOP\\OOP20_10_Maerzendorfer_Hinterberger\\Addressbuch\\personen.csv");

		if (!input.is_open())out_of_range{ "Could not open file" };

		string Stringseinzulesen;

		getline(input, Stringseinzulesen);
		while (getline(input, Stringseinzulesen))
		{
			SchreibenSieeineFunktionumdieTextdateipersonencsvohneweitereVerarbeitungineinenContainermitStringseinzulesen.push_back(Stringseinzulesen);
		}
		input.close();

		

		set<tuple<string, unsigned long long, string, string>> EineweitereFunktionsolldurchdenContaineriterierendenStringineinTuplestringunsignedintstringstringparsenundineinenweiterenContainerspeichernVerwendenSiefürdieseTransformationeinepassendestdMethodeundeinenLambdaAusdruckSolltenSiezumParsenweitereHilfsfunktionenbenötigensoimplementierenSiesieeinfach;

		for_each(SchreibenSieeineFunktionumdieTextdateipersonencsvohneweitereVerarbeitungineinenContainermitStringseinzulesen.begin(),
			SchreibenSieeineFunktionumdieTextdateipersonencsvohneweitereVerarbeitungineinenContainermitStringseinzulesen.end(),
			[&EineweitereFunktionsolldurchdenContaineriterierendenStringineinTuplestringunsignedintstringstringparsenundineinenweiterenContainerspeichernVerwendenSiefürdieseTransformationeinepassendestdMethodeundeinenLambdaAusdruckSolltenSiezumParsenweitereHilfsfunktionenbenötigensoimplementierenSiesieeinfach]
		(string& val) {

				auto splitted = split(val, ',');
				tuple <string, unsigned long long, string, string> tup = make_tuple(splitted[0], stoull(splitted[1]), splitted[2], splitted[3]);
				EineweitereFunktionsolldurchdenContaineriterierendenStringineinTuplestringunsignedintstringstringparsenundineinenweiterenContainerspeichernVerwendenSiefürdieseTransformationeinepassendestdMethodeundeinenLambdaAusdruckSolltenSiezumParsenweitereHilfsfunktionenbenötigensoimplementierenSiesieeinfach
					.insert(tup);
			}
		);
		
		map<string, tuple<string, unsigned long long, string, string>> ErweiternSieihrAdressbuchnunumdieSozialversicherungdereinzelnenPersonendieSieinderDateisvncsvfindenMergenSiedazudiebeidenTabellenWelcherContainerwaerealsErgebnisnunsinnvollwenndieSVNummernunderPrimaryKeyeinerPersonwaereVerwendenSiediesenContainertyp;

		ifstream inputSvn;

		inputSvn.open("C:\\Users\\minem\\Desktop\\FH\\OOP\\OOP20_10_Maerzendorfer_Hinterberger\\Addressbuch\\svn.csv");

		if (!inputSvn.is_open()) out_of_range {"Could not open file"};
		string svnsEinzulesen;

		getline(inputSvn, svnsEinzulesen);

		for_each(
			EineweitereFunktionsolldurchdenContaineriterierendenStringineinTuplestringunsignedintstringstringparsenundineinenweiterenContainerspeichernVerwendenSiefürdieseTransformationeinepassendestdMethodeundeinenLambdaAusdruckSolltenSiezumParsenweitereHilfsfunktionenbenötigensoimplementierenSiesieeinfach
			.begin(),
			EineweitereFunktionsolldurchdenContaineriterierendenStringineinTuplestringunsignedintstringstringparsenundineinenweiterenContainerspeichernVerwendenSiefürdieseTransformationeinepassendestdMethodeundeinenLambdaAusdruckSolltenSiezumParsenweitereHilfsfunktionenbenötigensoimplementierenSiesieeinfach
			.end(),
			[&ErweiternSieihrAdressbuchnunumdieSozialversicherungdereinzelnenPersonendieSieinderDateisvncsvfindenMergenSiedazudiebeidenTabellenWelcherContainerwaerealsErgebnisnunsinnvollwenndieSVNummernunderPrimaryKeyeinerPersonwaereVerwendenSiediesenContainertyp,
			&inputSvn]
			(tuple<string, unsigned long long, string, string> prsn)	
			{
				string str;
				getline(inputSvn, str);
				ErweiternSieihrAdressbuchnunumdieSozialversicherungdereinzelnenPersonendieSieinderDateisvncsvfindenMergenSiedazudiebeidenTabellenWelcherContainerwaerealsErgebnisnunsinnvollwenndieSVNummernunderPrimaryKeyeinerPersonwaereVerwendenSiediesenContainertyp
					.insert(
						make_pair(str, prsn)
					);
			}
		);
		
		inputSvn.close();
		
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}
}

