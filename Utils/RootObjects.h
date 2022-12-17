#include <vector>
#include <nlohmann/json.hpp>


template<typename T>
struct RootObject {
	std::vector<T> lists;
};
template<typename T>
inline void to_json(nlohmann::json& j, const RootObject<T>& obj)
{
	j = nlohmann::json
	{
		{
			"Root", obj.lists		
		}
	};
}
template<typename T>
inline void from_json(const nlohmann::json& j, RootObject<T>& obj)
{
	const nlohmann::json& sj = j.at("Root");
	obj.lists.resize(sj.size());
	std::copy(sj.begin(), sj.end(), obj.lists.begin());
}
