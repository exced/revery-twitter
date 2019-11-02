open Revery;
open Revery.UI;
open Revery.UI.Components;

type tweet = {
  tweet_id: string,
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
and tweet1 = {tweet_id: "1", text: "Tweet 1", author: user1}
and tweet2 = {tweet_id: "2", text: "Tweet 2", author: user1};

let rec user2 = {
  user_id: "2",
  username: "User 2",
  handle: "@user2",
  tweets: [tweet3, tweet4],
}
and tweet3 = {tweet_id: "3", text: "Tweet 3", author: user2}
and tweet4 = {tweet_id: "4", text: "Tweet 4", author: user2};

// Fixtures
let tweets = [tweet1, tweet2, tweet3, tweet4];

module Styles = {
  let container =
    Style.[
      width(500),
      padding(10),
      flexDirection(`Row),
      borderBottom(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
    ];

  let h = 49;

  let ppContainer =
    Style.[
      width(h),
      height(h),
      backgroundColor(Theme.Colors.blue),
      border(~color=Theme.Colors.blue, ~width=10),
      borderRadius(25.0),
    ];

  let contentContainer =
    Style.[
      backgroundColor(Colors.black),
      border(~color=Colors.black, ~width=1),
      borderRadius(5.0),
      overflow(`Hidden),
    ];

  let subContentContainer =
    Style.[
      backgroundColor(Colors.white),
      border(~color=Colors.white, ~width=1),
      borderRadius(5.0),
      overflow(`Hidden),
    ];

  let text =
    Style.[
      color(Colors.black),
      fontFamily("Roboto-Black.ttf"),
      fontSize(18),
    ];
};

let component = React.component("Tweet");

let make = (~id, ()) =>
  component(hooks => {
    let tweet = List.find(t => t.tweet_id == id, tweets);

    let content =
      switch (tweet) {
      | tweet =>
        <View style=Styles.container>
          <View style=Styles.ppContainer />
          <View>
            <Row>
              <Text style=Styles.text text={tweet.author.username} />
              <Text style=Styles.text text={tweet.author.handle} />
            </Row>
            <View style=Styles.contentContainer>
              <View style=Styles.subContentContainer>
                <View style=Style.[width(150), height(80)]>
                  <Text style=Styles.text text={tweet.text} />
                </View>
              </View>
            </View>
          </View>
        </View>
      | _ => <Text style=Styles.text text="Tweet not found" />
      };

    (hooks, content);
  });

let createElement = (~children as _, ~id, ()) => make(~id, ());