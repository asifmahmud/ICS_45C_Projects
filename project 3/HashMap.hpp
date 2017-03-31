
#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>



class HashMap
{
public:

	typedef std::function<unsigned int(const std::string&)> HashFunction;
	
	static const unsigned int INITIAL_BUCKET_COUNT = 10;


public:

	HashMap();

	HashMap(HashFunction hashFunction);

	HashMap(const HashMap& hm);
	~HashMap();
	HashMap& operator=(const HashMap& hm);

	void add(const std::string& key, const std::string& value);


	void remove(const std::string& key);

	void clear();

	bool contains(const std::string& key) const;


	std::string value(const std::string& key) const;

	unsigned int size() const;


	unsigned int bucketCount() const;

	double loadFactor() const;


	unsigned int maxBucketSize() const;

	

private:

	struct Node
	{
		std::string key;
		std::string value;
		Node* next;
	};

	Node* HashTable[INITIAL_BUCKET_COUNT];

	HashFunction hashFunction;

	unsigned int proper_index(unsigned int index) const;

	double index_items(int index) const;

	double number_of_items() const;

	void hash_copy(Node* target, Node* source, unsigned int size);

	unsigned int bucket_count;

	void index_remove(unsigned int index);


};



#endif // HASHMAP_HPP
