#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
template<typename T>
struct RootObject {
	std::vector<T> lists;
};
template<typename T>
void to_json(json& j, const RootObject<T>& obj)
{
	j = json
	{
		{
			"Root", obj.lists		
		}
	};
}
template<typename T>
void from_json(const json& j, RootObject<T>& obj)
{
	const json& sj = j.at("Root");
	obj.lists.resize(sj.size());
	std::copy(sj.begin(), sj.end(), obj.lists.begin());
}