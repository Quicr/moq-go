# Chat Application Design

This document describes the design of a MoQ-based chat application using namespace subscriptions.

## Overview

The chat application demonstrates:
- Subscribe namespace for discovering chat participants
- Dynamic track subscription for receiving messages
- Publishing chat messages with proper grouping

## Namespace Structure

```
Common Namespace (all clients subscribe):
  /<chat-app>/<session-id>

Per-User Publish Track:
  /<chat-app>/<session-id>/<user-did>/text

Track Name:
  "text" (media type for chat messages)
```

### Tuple Breakdown

1. **chat-app**: Application identifier (e.g., "chat")
2. **session-id**: Chat room/session identifier (user input)
3. **user-did**: User's DID (Decentralized Identifier, generated like ATProto)
4. **text**: Track name indicating text/chat media type

## DID Generation

Following ATProto-style DID generation:
- Format: `did:plc:<random-32-char-base32>`
- Example: `did:plc:abcdefghijklmnopqrstuvwx`

## Message Flow

### 1. Joining a Chat

1. User provides session-id and username
2. Client generates a DID from the username
3. Client subscribes to the common namespace: `/<chat-app>/<session-id>`
4. When new tracks are announced, client subscribes to receive messages

### 2. Sending Messages

1. Client creates a publish track: `/<chat-app>/<session-id>/<user-did>/text`
2. Messages are grouped: every 10 messages start a new group
3. First group ID uses least 32 bits of current time
4. Each message is a MoQ object within the group

### 3. Receiving Messages

1. Namespace subscription notifies when new tracks appear
2. Client subscribes to each announced track
3. Objects received contain chat messages with sender info

## Object Structure

```
Headers:
  - GroupID: Starting from current_time & 0xFFFFFFFF, increments every 10 messages
  - ObjectID: 0-9 within each group
  - Priority: 128 (default)
  - TTL: 30000ms (30 seconds)

Payload (JSON):
  {
    "from": "<user-did>",
    "name": "<display-name>",
    "text": "<message>",
    "ts": <unix-timestamp-ms>
  }
```

## Example Session

```
$ ./chat -server localhost:4433 -session gaming-room
Enter your username: alice

Generating DID: did:plc:abcdefghijklmnopqrstuvwx

Namespace tuples:
  [0] chat
  [1] gaming-room

Subscribe namespace: chat/gaming-room
Publish track: chat/gaming-room/did:plc:abcdefghijklmnopqrstuvwx/text

Track tuples:
  [0] chat
  [1] gaming-room
  [2] did:plc:abcdefghijklmnopqrstuvwx

Track name: text

Entered chat room. Type messages and press Enter to send.

> Hello everyone!
Published [1234567890:0] Hello everyone!

[bob] Hey Alice!

> How's it going?
Published [1234567890:1] How's it going?
```

## Implementation Notes

1. **Thread Safety**: All callbacks run in goroutines to avoid blocking
2. **Message Ordering**: GroupOrder ascending ensures messages arrive in order
3. **Late Join**: FilterType latest-group helps new joiners get recent context
4. **Cleanup**: Proper unsubscribe and unpublish on exit
