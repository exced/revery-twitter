let next_tweet_id = ref(5);

type tweet = {
  tweet_id: string,
  ref: option(tweet),
  text: string,
  author,
}
and author = {
  user_id: string,
  username: string,
  handle: string,
  tweets: list(tweet),
};

let rec user1 = {
  user_id: "1",
  username: "User 1",
  handle: "@user1",
  tweets: [tweet1, tweet2],
}
and tweet1 = {tweet_id: "1", ref: None, text: "Tweet 1", author: user1}
and tweet2 = {tweet_id: "2", ref: None, text: "Tweet 2", author: user1};

let rec user2 = {
  user_id: "2",
  username: "User 2",
  handle: "@user2",
  tweets: [tweet3, tweet4],
}
and tweet3 = {
  tweet_id: "3",
  ref: Some(tweet1),
  text: "Tweet 3",
  author: user2,
}
and tweet4 = {tweet_id: "4", ref: None, text: "Tweet 4", author: user2};

let tweets = [tweet1, tweet2, tweet3, tweet4];