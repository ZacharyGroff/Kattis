package main

import "fmt"

func main() {
	var tests int
	fmt.Scanf("%d\n", &tests)
	for i := 0; i < tests; i++ {
		handleTestCase()
	}
}

func handleTestCase() {
	inp1, inp2 := scanTestCase()
	printInputs(inp1, inp2)
	result := buildResult(inp1, inp2)
	fmt.Printf("%s\n\n", result)
}

func scanTestCase() (string, string){
	var inp1, inp2 string
	fmt.Scanf("%s\n%s\n", &inp1, &inp2)

	return inp1, inp2
}

func printInputs(inp1 string, inp2 string) {
	fmt.Println(inp1)
	fmt.Println(inp2)
}

func buildResult(inp1 string, inp2 string) string {
	var result string
	for i := 0; i < len(inp1); i++ {
		if inp1[i] != inp2[i] {
			result += "*"
		} else {
			result += "."
		}
	}

	return result
}
