# typeswitch library
Little library to support access to C++17 type-safe union types - std::variant and std::any. 

Library provides two macros:
- ```typeswitch([variant|any])``` - analogue to C++ ```switch```
- ```typecase(type, name)``` - If type is holded ```name``` is reference to holded type and code after is executed. Should be followed by single statement or compound statement.

### Simple example (for more ```example.cc``` file in repository)
```c++
std::variant<int, std::string> variant;
typeswitch (variant) {
	typecase(int, val): std::cout << "I'm holding int of value: " << val << '\n';
	typecase(std::string, str): 
		std::cout << "I'm holding std::string of value: " << std::quoted(str) << '\n';
}
```

## Future goals
- add constexpr compatibility for std::variant access

This code is distributed under the MIT license. See LICENSE for details.
