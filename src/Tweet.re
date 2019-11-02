open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container =
    Style.[
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
    let content =
      switch (Data.getTweet(id)) {
      | Some(tweet) =>
        <View style=Styles.container>
          <View style=Styles.ppContainer />
          <View>
            <Row>
              <Text style=Styles.text text={tweet.author.username} />
              <Text style=Styles.text text={tweet.author.handle} />
            </Row>
            <View style=Style.[width(150), height(80)]>
              <Text style=Styles.text text={tweet.text} />
            </View>
            {switch (tweet.ref) {
             | Some(tweetRef) =>
               <View style=Styles.contentContainer>
                 <View style=Styles.subContentContainer>
                   <View style=Style.[width(150), height(80)]>
                     <Text style=Styles.text text="TWEET REF" />
                   </View>
                 </View>
               </View>
             | None => <View />
             }}
          </View>
        </View>
      | None => <Text style=Styles.text text="Tweet not found" />
      };

    (hooks, content);
  });

let createElement = (~children as _, ~id, ()) => make(~id, ());