package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var tests, result int
	fmt.Scanln(&tests)
	for i := 0; i < tests; i++ {
		result += handleTestCase()
	}
	fmt.Println(result)
}

func handleTestCase() int {
	input := getInput()
	return calculate(input)
}

func getInput() string {
	var input string
	fmt.Scanln(&input)
	return input
}

func calculate(input string) int {
	lastIndex := len(input) - 1
	base, _ := strconv.ParseFloat(input[:lastIndex], 64)
	pow, _ := strconv.ParseFloat(string(input[lastIndex]), 64)
	return int(math.Pow(base, pow))
}
