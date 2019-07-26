package main

import (
    "fmt"
)

func main() {
    var gold, silver, copper int
    fmt.Scanln(&gold, &silver, &copper)

    bp := getBuyingPower(gold, silver, copper)
    victory, treasure := getBestCards(bp)

    if victory != "" {
        fmt.Printf("%s or %s\n", victory, treasure)
    } else {
        fmt.Printf("%s\n", treasure)
    }
}

func getBuyingPower(gold int, silver int, copper int) int {
    return (gold * 3) + (silver * 2) + copper
}

func getBestCards(bp int) (string, string){
    vc := getVictoryCard(bp)
    tc := getTreasureCard(bp)
    return vc, tc
}

func getVictoryCard(bp int) string {
    if bp >= 8 {
        return "Province"
    } else if bp >= 5 {
        return "Duchy"
    } else if bp >= 2 {
        return "Estate"
    } else {
        return ""
    }
}

func getTreasureCard(bp int) string {
    if bp >= 6 {
        return "Gold"
    } else if bp >= 3 {
        return "Silver"
    } else {
        return "Copper"
    }
}
