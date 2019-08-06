fn main() {
  let mut votes = std::collections::HashMap::new();
  count_votes(&mut votes);

  let (winner, winning_votes) = get_winner(&votes);
  *votes.get_mut(&winner).unwrap() = 0;
  let (_, second_votes) = get_winner(&votes);

  if winning_votes == second_votes {
    println!("Runoff!");
  } else {
    println!("{}", winner);
  }
}

fn count_votes(votes: &mut std::collections::HashMap<String, u32>) {
  loop {
    let line = get_input_line();
    if line == "***\n" {
      break;
    }

    update_map(line, votes);
  }
}

fn get_input_line() -> String {
		let mut input = String::new();
		let _ = std::io::stdin().read_line(&mut input);

    input
}

fn update_map(key: String, map: &mut std::collections::HashMap<String, u32>) {
  let count = map.entry(key).or_insert(0);
 *count += 1;
}

fn get_winner(votes: &std::collections::HashMap<String, u32>) -> (String, u32) {
  let mut winner = String::new();
  let mut winning_votes = 0;

  match votes.iter().max_by_key(|kvp| kvp.1) {
    Some(x) => {
      winner = x.0.clone();
      winning_votes = x.1.clone();
    },
    _ => (),
  }

  (winner, winning_votes)
}
