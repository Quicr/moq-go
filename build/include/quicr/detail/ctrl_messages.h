// Generated from: draft-ietf-moq-transport-16_filters_edited.txt

#pragma once
#include <vector>
#include <quicr/common.h>
#include <quicr/track_name.h>
#include <quicr/detail/ctrl_message_types.h>

namespace quicr::messages {  

        
    
    // usings
    using SetupParameters = quicr::messages::ParameterList<quicr::messages::SetupParameterType>;
    using NewSessionURI = quicr::Bytes;
    using MaxRequestID = std::uint64_t;
    using MaximumRequestID = std::uint64_t;
    using RequestID = std::uint64_t;
    using Parameters = quicr::messages::ParameterList<quicr::messages::ParameterType>;
    using ErrorCode = quicr::messages::ErrorCode;
    using RetryInterval = std::uint64_t;
    using ErrorReason = quicr::Bytes;
    using TrackNamespace = quicr::TrackNamespace;
    using TrackName = quicr::messages::TrackName;
    using TrackAlias = std::uint64_t;
    using TrackExtensions = quicr::messages::TrackExtensions;
    using ExistingRequestID = std::uint64_t;
    using PublishDoneStatusCode = quicr::messages::PublishDoneStatusCode;
    using StreamCount = std::uint64_t;
    using FetchType = quicr::messages::FetchType;
    using Standalone = quicr::messages::StandaloneFetch;
    using Joining = quicr::messages::JoiningFetch;
    using EndOfTrack = std::uint8_t;
    using EndLocation = quicr::messages::Location;
    using TrackNamespaceSuffix = quicr::TrackNamespace;
    using TrackNamespacePrefix = quicr::TrackNamespace;
    using SubscribeOptions = quicr::messages::SubscribeOptions;


    // enums
    enum class ControlMessageType : uint64_t
    {
        kRequestUpdate = 0x2,
        kSubscribe = 0x3,
        kSubscribeOk = 0x4,
        kRequestError = 0x5,
        kPublishNamespace = 0x6,
        kRequestOk = 0x7,
        kNamespace = 0x8,
        kPublishNamespaceDone = 0x9,
        kUnsubscribe = 0xa,
        kPublishDone = 0xb,
        kPublishNamespaceCancel = 0xc,
        kTrackStatus = 0xd,
        kNamespaceDone = 0xe,
        kGoaway = 0x10,
        kSubscribeNamespace = 0x11,
        kMaxRequestId = 0x15,
        kFetch = 0x16,
        kFetchCancel = 0x17,
        kFetchOk = 0x18,
        kRequestsBlocked = 0x1a,
        kPublish = 0x1d,
        kPublishOk = 0x1e,
        kClientSetup = 0x20,
        kServerSetup = 0x21,
    };
    /**
     * @brief RequestUpdate
     */
    struct RequestUpdate
    {        

    public:
        // Default constructor
        RequestUpdate () {}
        
        // All fields constructor
        RequestUpdate (
            RequestID request_id,
            ExistingRequestID existing_request_id,
            Parameters parameters):
                request_id(request_id),
                existing_request_id(existing_request_id),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        ExistingRequestID existing_request_id;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const RequestUpdate& msg);
    BytesSpan operator>>(BytesSpan buffer, RequestUpdate& msg);    

    /**
     * @brief Subscribe
     */
    struct Subscribe
    {        

    public:
        // Default constructor
        Subscribe () {}
        
        // All fields constructor
        Subscribe (
            RequestID request_id,
            TrackNamespace track_namespace,
            TrackName track_name,
            Parameters parameters):
                request_id(request_id),
                track_namespace(track_namespace),
                track_name(track_name),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        TrackNamespace track_namespace;
        TrackName track_name;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const Subscribe& msg);
    BytesSpan operator>>(BytesSpan buffer, Subscribe& msg);    

    /**
     * @brief SubscribeOk
     */
    struct SubscribeOk
    {        

    public:
        // Default constructor
        SubscribeOk () {}
        
        // All fields constructor
        SubscribeOk (
            RequestID request_id,
            TrackAlias track_alias,
            Parameters parameters,
            TrackExtensions track_extensions):
                request_id(request_id),
                track_alias(track_alias),
                parameters(parameters),
                track_extensions(track_extensions)
            {}

            

    public:
        RequestID request_id;
        TrackAlias track_alias;
        Parameters parameters;
        TrackExtensions track_extensions;
    };

    Bytes& operator<<(Bytes& buffer, const SubscribeOk& msg);
    BytesSpan operator>>(BytesSpan buffer, SubscribeOk& msg);    

    /**
     * @brief RequestError
     */
    struct RequestError
    {        

    public:
        // Default constructor
        RequestError () {}
        
        // All fields constructor
        RequestError (
            RequestID request_id,
            ErrorCode error_code,
            RetryInterval retry_interval,
            ErrorReason error_reason):
                request_id(request_id),
                error_code(error_code),
                retry_interval(retry_interval),
                error_reason(error_reason)
            {}

            

    public:
        RequestID request_id;
        ErrorCode error_code;
        RetryInterval retry_interval;
        ErrorReason error_reason;
    };

    Bytes& operator<<(Bytes& buffer, const RequestError& msg);
    BytesSpan operator>>(BytesSpan buffer, RequestError& msg);    

    /**
     * @brief PublishNamespace
     */
    struct PublishNamespace
    {        

    public:
        // Default constructor
        PublishNamespace () {}
        
        // All fields constructor
        PublishNamespace (
            RequestID request_id,
            TrackNamespace track_namespace,
            Parameters parameters):
                request_id(request_id),
                track_namespace(track_namespace),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        TrackNamespace track_namespace;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const PublishNamespace& msg);
    BytesSpan operator>>(BytesSpan buffer, PublishNamespace& msg);    

    /**
     * @brief RequestOk
     */
    struct RequestOk
    {        

    public:
        // Default constructor
        RequestOk () {}
        
        // All fields constructor
        RequestOk (
            RequestID request_id,
            Parameters parameters):
                request_id(request_id),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const RequestOk& msg);
    BytesSpan operator>>(BytesSpan buffer, RequestOk& msg);    

    /**
     * @brief Namespace
     */
    struct Namespace
    {        

    public:
        // Default constructor
        Namespace () {}
        
        // All fields constructor
        Namespace (
            TrackNamespaceSuffix track_namespace_suffix):
                track_namespace_suffix(track_namespace_suffix)
            {}

            

    public:
        TrackNamespaceSuffix track_namespace_suffix;
    };

    Bytes& operator<<(Bytes& buffer, const Namespace& msg);
    BytesSpan operator>>(BytesSpan buffer, Namespace& msg);    

    /**
     * @brief PublishNamespaceDone
     */
    struct PublishNamespaceDone
    {        

    public:
        // Default constructor
        PublishNamespaceDone () {}
        
        // All fields constructor
        PublishNamespaceDone (
            RequestID request_id):
                request_id(request_id)
            {}

            

    public:
        RequestID request_id;
    };

    Bytes& operator<<(Bytes& buffer, const PublishNamespaceDone& msg);
    BytesSpan operator>>(BytesSpan buffer, PublishNamespaceDone& msg);    

    /**
     * @brief Unsubscribe
     */
    struct Unsubscribe
    {        

    public:
        // Default constructor
        Unsubscribe () {}
        
        // All fields constructor
        Unsubscribe (
            RequestID request_id):
                request_id(request_id)
            {}

            

    public:
        RequestID request_id;
    };

    Bytes& operator<<(Bytes& buffer, const Unsubscribe& msg);
    BytesSpan operator>>(BytesSpan buffer, Unsubscribe& msg);    

    /**
     * @brief PublishDone
     */
    struct PublishDone
    {        

    public:
        // Default constructor
        PublishDone () {}
        
        // All fields constructor
        PublishDone (
            RequestID request_id,
            PublishDoneStatusCode status_code,
            StreamCount stream_count,
            ErrorReason error_reason):
                request_id(request_id),
                status_code(status_code),
                stream_count(stream_count),
                error_reason(error_reason)
            {}

            

    public:
        RequestID request_id;
        PublishDoneStatusCode status_code;
        StreamCount stream_count;
        ErrorReason error_reason;
    };

    Bytes& operator<<(Bytes& buffer, const PublishDone& msg);
    BytesSpan operator>>(BytesSpan buffer, PublishDone& msg);    

    /**
     * @brief PublishNamespaceCancel
     */
    struct PublishNamespaceCancel
    {        

    public:
        // Default constructor
        PublishNamespaceCancel () {}
        
        // All fields constructor
        PublishNamespaceCancel (
            RequestID request_id,
            ErrorCode error_code,
            ErrorReason error_reason):
                request_id(request_id),
                error_code(error_code),
                error_reason(error_reason)
            {}

            

    public:
        RequestID request_id;
        ErrorCode error_code;
        ErrorReason error_reason;
    };

    Bytes& operator<<(Bytes& buffer, const PublishNamespaceCancel& msg);
    BytesSpan operator>>(BytesSpan buffer, PublishNamespaceCancel& msg);    

    /**
     * @brief TrackStatus
     */
    struct TrackStatus
    {        

    public:
        // Default constructor
        TrackStatus () {}
        
        // All fields constructor
        TrackStatus (
            RequestID request_id,
            TrackNamespace track_namespace,
            TrackName track_name):
                request_id(request_id),
                track_namespace(track_namespace),
                track_name(track_name)
            {}

            

    public:
        RequestID request_id;
        TrackNamespace track_namespace;
        TrackName track_name;
    };

    Bytes& operator<<(Bytes& buffer, const TrackStatus& msg);
    BytesSpan operator>>(BytesSpan buffer, TrackStatus& msg);    

    /**
     * @brief NamespaceDone
     */
    struct NamespaceDone
    {        

    public:
        // Default constructor
        NamespaceDone () {}
        
        // All fields constructor
        NamespaceDone (
            TrackNamespaceSuffix track_namespace_suffix):
                track_namespace_suffix(track_namespace_suffix)
            {}

            

    public:
        TrackNamespaceSuffix track_namespace_suffix;
    };

    Bytes& operator<<(Bytes& buffer, const NamespaceDone& msg);
    BytesSpan operator>>(BytesSpan buffer, NamespaceDone& msg);    

    /**
     * @brief Goaway
     */
    struct Goaway
    {        

    public:
        // Default constructor
        Goaway () {}
        
        // All fields constructor
        Goaway (
            NewSessionURI new_session_uri):
                new_session_uri(new_session_uri)
            {}

            

    public:
        NewSessionURI new_session_uri;
    };

    Bytes& operator<<(Bytes& buffer, const Goaway& msg);
    BytesSpan operator>>(BytesSpan buffer, Goaway& msg);    

    /**
     * @brief SubscribeNamespace
     */
    struct SubscribeNamespace
    {        

    public:
        // Default constructor
        SubscribeNamespace () {}
        
        // All fields constructor
        SubscribeNamespace (
            RequestID request_id,
            TrackNamespacePrefix track_namespace_prefix,
            SubscribeOptions subscribe_options,
            Parameters parameters):
                request_id(request_id),
                track_namespace_prefix(track_namespace_prefix),
                subscribe_options(subscribe_options),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        TrackNamespacePrefix track_namespace_prefix;
        SubscribeOptions subscribe_options;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const SubscribeNamespace& msg);
    BytesSpan operator>>(BytesSpan buffer, SubscribeNamespace& msg);    

    /**
     * @brief MaxRequestId
     */
    struct MaxRequestId
    {        

    public:
        // Default constructor
        MaxRequestId () {}
        
        // All fields constructor
        MaxRequestId (
            MaxRequestID max_request_id):
                max_request_id(max_request_id)
            {}

            

    public:
        MaxRequestID max_request_id;
    };

    Bytes& operator<<(Bytes& buffer, const MaxRequestId& msg);
    BytesSpan operator>>(BytesSpan buffer, MaxRequestId& msg);    

    /**
     * @brief Fetch
     */
    struct Fetch
    {        
    public:
        // Optional Groups
        struct Group_0 {
            Standalone standalone;
        };
        struct Group_1 {
            Joining joining;
        };

    public:
        // Have optionals - delete default constructor
        Fetch () = delete;
        
        // All fields constructor
        Fetch (
            RequestID request_id,
            FetchType fetch_type,
            std::optional<Fetch::Group_0> group_0,
            std::optional<Fetch::Group_1> group_1,
            Parameters parameters):
                request_id(request_id),
                fetch_type(fetch_type),
                group_0(group_0),
                group_1(group_1),
                parameters(parameters)
            {}

            
        // Optional callback constructor 

        Fetch (
            std::function<void (Fetch&)> group_0_cb,
            std::function<void (Fetch&)> group_1_cb
        );

    public:
        RequestID request_id;
        FetchType fetch_type;
        std::function<void (Fetch&)> group_0_cb;
        std::optional<Fetch::Group_0> group_0;
        std::function<void (Fetch&)> group_1_cb;
        std::optional<Fetch::Group_1> group_1;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const Fetch& msg);
    BytesSpan operator>>(BytesSpan buffer, Fetch& msg);    

    Bytes& operator<<(Bytes& buffer, const std::optional<Fetch::Group_0>& grp);
    BytesSpan operator>>(BytesSpan buffer, std::optional<Fetch::Group_0>& grp);

    Bytes& operator<<(Bytes& buffer, const std::optional<Fetch::Group_1>& grp);
    BytesSpan operator>>(BytesSpan buffer, std::optional<Fetch::Group_1>& grp);

    /**
     * @brief FetchCancel
     */
    struct FetchCancel
    {        

    public:
        // Default constructor
        FetchCancel () {}
        
        // All fields constructor
        FetchCancel (
            RequestID request_id):
                request_id(request_id)
            {}

            

    public:
        RequestID request_id;
    };

    Bytes& operator<<(Bytes& buffer, const FetchCancel& msg);
    BytesSpan operator>>(BytesSpan buffer, FetchCancel& msg);    

    /**
     * @brief FetchOk
     */
    struct FetchOk
    {        

    public:
        // Default constructor
        FetchOk () {}
        
        // All fields constructor
        FetchOk (
            RequestID request_id,
            EndOfTrack end_of_track,
            EndLocation end_location,
            Parameters parameters,
            TrackExtensions track_extensions):
                request_id(request_id),
                end_of_track(end_of_track),
                end_location(end_location),
                parameters(parameters),
                track_extensions(track_extensions)
            {}

            

    public:
        RequestID request_id;
        EndOfTrack end_of_track;
        EndLocation end_location;
        Parameters parameters;
        TrackExtensions track_extensions;
    };

    Bytes& operator<<(Bytes& buffer, const FetchOk& msg);
    BytesSpan operator>>(BytesSpan buffer, FetchOk& msg);    

    /**
     * @brief RequestsBlocked
     */
    struct RequestsBlocked
    {        

    public:
        // Default constructor
        RequestsBlocked () {}
        
        // All fields constructor
        RequestsBlocked (
            MaximumRequestID maximum_request_id):
                maximum_request_id(maximum_request_id)
            {}

            

    public:
        MaximumRequestID maximum_request_id;
    };

    Bytes& operator<<(Bytes& buffer, const RequestsBlocked& msg);
    BytesSpan operator>>(BytesSpan buffer, RequestsBlocked& msg);    

    /**
     * @brief Publish
     */
    struct Publish
    {        

    public:
        // Default constructor
        Publish () {}
        
        // All fields constructor
        Publish (
            RequestID request_id,
            TrackNamespace track_namespace,
            TrackName track_name,
            TrackAlias track_alias,
            Parameters parameters,
            TrackExtensions track_extensions):
                request_id(request_id),
                track_namespace(track_namespace),
                track_name(track_name),
                track_alias(track_alias),
                parameters(parameters),
                track_extensions(track_extensions)
            {}

            

    public:
        RequestID request_id;
        TrackNamespace track_namespace;
        TrackName track_name;
        TrackAlias track_alias;
        Parameters parameters;
        TrackExtensions track_extensions;
    };

    Bytes& operator<<(Bytes& buffer, const Publish& msg);
    BytesSpan operator>>(BytesSpan buffer, Publish& msg);    

    /**
     * @brief PublishOk
     */
    struct PublishOk
    {        

    public:
        // Default constructor
        PublishOk () {}
        
        // All fields constructor
        PublishOk (
            RequestID request_id,
            Parameters parameters):
                request_id(request_id),
                parameters(parameters)
            {}

            

    public:
        RequestID request_id;
        Parameters parameters;
    };

    Bytes& operator<<(Bytes& buffer, const PublishOk& msg);
    BytesSpan operator>>(BytesSpan buffer, PublishOk& msg);    

    /**
     * @brief ClientSetup
     */
    struct ClientSetup
    {        

    public:
        // Default constructor
        ClientSetup () {}
        
        // All fields constructor
        ClientSetup (
            SetupParameters setup_parameters):
                setup_parameters(setup_parameters)
            {}

            

    public:
        SetupParameters setup_parameters;
    };

    Bytes& operator<<(Bytes& buffer, const ClientSetup& msg);
    BytesSpan operator>>(BytesSpan buffer, ClientSetup& msg);    

    /**
     * @brief ServerSetup
     */
    struct ServerSetup
    {        

    public:
        // Default constructor
        ServerSetup () {}
        
        // All fields constructor
        ServerSetup (
            SetupParameters setup_parameters):
                setup_parameters(setup_parameters)
            {}

            

    public:
        SetupParameters setup_parameters;
    };

    Bytes& operator<<(Bytes& buffer, const ServerSetup& msg);
    BytesSpan operator>>(BytesSpan buffer, ServerSetup& msg);    


    Bytes& operator<<(Bytes& buffer, ControlMessageType message_type);

} // namespace
