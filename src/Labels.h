#ifndef _LABELS_H_
#define _LABELS_H_

static const char L_PORTAL_PAGES_P[] PROGMEM = R"raw(
[
  {
    "title": "Welcome",
    "uri": "/",
    "menu": false,
    "element": [
      {
        "name": "header",
        "type": "ACText",
        "value": "<h2>Welcome</h2>",
        "style": "text-align:center;color:#2f4f4f;padding:10px;"
      },
      {
        "name": "caption",
        "type": "ACText",
        "value": "Some text...",
        "style": "color:#4682b4;"
      }
    ]
  }
]
)raw";

#endif