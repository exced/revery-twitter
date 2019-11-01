open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container = Style.[padding(10), flexDirection(`Row)];

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
    (
      hooks,
      <View style=Styles.container>
        <View style=Styles.ppContainer />
        <Text style=Styles.text text="Name" />
        <Text style=Styles.text text="Tweet" />
        <View style=Styles.contentContainer>
          <View style=Styles.subContentContainer>
            <View style=Style.[width(150), height(80)]>
              <Text style=Styles.text text="Content" />
            </View>
          </View>
        </View>
      </View>,
    )
  });

let createElement = (~children as _, ~id, ()) => make(~id, ());