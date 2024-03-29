open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container =
    Style.[
      padding(Theme.Spacing.m),
      flexDirection(`Row),
      borderBottom(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
    ];

  let ppContainer =
    Style.[
      width(Theme.Spacing.xxxl),
      height(Theme.Spacing.xxxl),
      backgroundColor(Theme.Colors.blue),
      border(~color=Theme.Colors.blue, ~width=10),
      borderRadius(25.0),
      marginRight(Theme.Spacing.l),
    ];

  let authorRowContainer = Style.[flexDirection(`Row)];

  let text =
    Style.[
      color(Theme.Colors.black),
      fontFamily("Roboto-Black.ttf"),
      fontSize(15),
    ];

  let refContainer = Style.[padding(20)];
};

let component = React.component("Tweet");

let make = (~tweet, ()) =>
  component(hooks => {
    let render = (tweet: Data.tweet) =>
      <View>
        <View style=Styles.authorRowContainer>
          <Text style=Styles.text text={tweet.author.username} />
          <Text style=Styles.text text={tweet.author.handle} />
        </View>
        <View style=Style.[width(150), height(80)]>
          <Text style=Styles.text text={tweet.text} />
        </View>
        {switch (tweet.img) {
         | Some(src) => <Image src style=Style.[width(300), height(200)] />
         | None => <View />
         }}
      </View>;

    (
      hooks,
      Data.(
        <View style=Styles.container>
          <View style=Styles.ppContainer />
          {render(tweet)}
          {switch (tweet.ref) {
           | Some(tweetRef) =>
             <View style=Styles.refContainer>
               <Bordered> {render(tweetRef)} </Bordered>
             </View>
           | None => <View />
           }}
        </View>
      ),
    );
  });

let createElement = (~children as _, ~tweet, ()) => make(~tweet, ());