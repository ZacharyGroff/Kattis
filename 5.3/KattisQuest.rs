use std::collections::HashMap;
use std::collections::BinaryHeap;

fn main() {
  let n = get_n();
  let mut map: HashMap<u32, BinaryHeap<u32>> = HashMap::new();
  for _ in 0..n {
    let input = try_get_input_line();
    if input == "" {
      break;
    } else if input.contains("add") {
      let (energy, gold) = parse_add(input);
      add(&mut map, energy, gold);
    } else if input.contains("query") {
      let energy = parse_query(input);
      let result = query(&mut map, energy);
      println!("{}", result);
    }
  }
}

fn get_n() -> u32 {
  let mut input = String::new();
  let _ = std::io::stdin().read_line(&mut input);
  
  input.trim().parse().expect("wanted a number")
}

fn try_get_input_line() -> String {
  let mut input = String::new();
  match std::io::stdin().read_line(&mut input) {
    Ok(_) => return input.trim().to_string(),
    _ => return String::new(),
  }
}

fn parse_add(input: String) -> (u32, u32) {
  let vec: Vec<String> = input.split(" ").map(String::from).collect();
  let energy: u32 = vec[1].parse().expect("wanted a number");
  let gold: u32 = vec[2].parse().expect("wanted a number");

  (energy, gold)
}

fn parse_query(input: String) -> u32 {
  let vec: Vec<String> = input.split(" ").map(String::from).collect();
  let energy: u32 = vec[1].parse().expect("wanted a number");

  energy
}

fn add(map: &mut HashMap<u32, BinaryHeap<u32>>, energy: u32, gold: u32) {
  let heap = map.entry(energy).or_insert(BinaryHeap::new());
  heap.push(gold);
} 

fn query(map: &mut HashMap<u32, BinaryHeap<u32>>, energy: u32) -> u32 {
  let mut count = energy.clone();
  let mut remaining_energy = energy.clone();
  let mut total_gold = 0;
  while count > 0 && remaining_energy >= count {
    let heap = map.entry(count).or_insert(BinaryHeap::new());
    if heap.peek() != None {
      match heap.pop() {
        Some(gold) => {
          total_gold += gold;
          remaining_energy -= count;
        },
        _ => (),
      }
    }
    count -= 1;
  }

  total_gold
}
