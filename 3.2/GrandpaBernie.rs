 use std::collections::HashMap;
 use std::collections::BinaryHeap;
 
 fn main() {
  let n = get_input_line::<u16>().unwrap()[0];
  let mut trips: HashMap<String, BinaryHeap<u16>> = HashMap::new();
  for _ in 0..n {
    let line = get_input_line::<String>().unwrap();
    update_trips(line, &mut trips)
  }
  let queries = get_input_line::<u16>().unwrap()[0];
  for _ in 0..queries {
    let line = get_input_line::<String>().unwrap();
    let year = query(line, &trips);
    println!("{}", year);
  }
 }

fn get_input_line<T: std::str::FromStr>() -> Result<Vec<T>, <T as std::str::FromStr>::Err> {
		let mut input = String::new();
		let _ = std::io::stdin().read_line(&mut input);
		
		input.split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn update_trips(line: Vec<String>, trips: &mut HashMap<String, BinaryHeap<u16>>) {
  let destination = line[0].clone();
  let year: u16 = line[1].parse().unwrap();
  let heap = trips.entry(destination).or_insert(BinaryHeap::new());
  heap.push(year);
}

fn query(line: Vec<String>, trips: &HashMap<String, BinaryHeap<u16>>) -> u16{
  let destination = line[0].clone();
  let nth_trip: u8 = line[1].parse().unwrap();

  let mut year: u16 = 0;
  for _ in 0..nth_trip {
    let heap = trips.entry(destination).or_default();
    year = heap.pop();
  }

  year
}
