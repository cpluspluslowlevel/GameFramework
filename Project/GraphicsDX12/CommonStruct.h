#ifndef _FRAMEWORK_GRAPHICSDX12_COMMONSTRUCT_H_
#define _FRAMEWORK_GRAPHICSDX12_COMMONSTRUCT_H_

namespace Framework::GraphicsDX12
{

    template<typename Type>
    concept IsCOMType = std::is_base_of_v<IUnknown, Type>;

    template<typename COMType> requires IsCOMType<COMType>
    class COMPTR
    {
    public:
        COMPTR() : m_ptr{ nullptr } {}
        COMPTR(COMType* ptr) : m_ptr{ ptr }
        {
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }
        }

        COMPTR(const COMPTR& lvalue) : m_ptr{ lvalue.m_ptr }
        {
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }
        }

        COMPTR(COMPTR&& rvalue) noexcept : m_ptr{ rvalue.m_ptr }
        {
            rvalue.m_ptr = nullptr;
        }

        ~COMPTR() noexcept
        {
            Core::SafeRelease(m_ptr);
        }

        COMPTR& operator=(const COMPTR& lvalue)
        {

            Core::SafeRelease(m_ptr);

            m_ptr = lvalue.m_ptr;
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }

            return *this;

        }

        COMPTR& operator=(COMPTR&& rvalue) noexcept
        {

            m_ptr = rvalue.m_ptr;

            rvalue.m_ptr = nullptr;

            return *this;

        }

        COMType* operator->()
        {
            return m_ptr;
        }

        const COMType* operator->() const
        {
            return m_ptr;
        }

        operator COMType* ()
        {
            return m_ptr;
        }

        operator const COMType* ()
        {
            return m_ptr;
        }

        /// <summary>
        /// ���� COM��ü�� �����ϴ�.
        /// </summary>
        void Reset()
        {
            Core::SafeRelease(m_ptr);
        }


        /// <summary>
        /// ���ο� COM��ü�� ������ �� �ƿ� �Ķ���Ͱ� �ʿ��� ��� ����մϴ�. ������ �������ִ� ��ü�� �����ϴ�.
        /// </summary>
        /// <returns></returns>
        COMType** ResetByOutParameter()
        {
            Core::SafeRelease(m_ptr);
            return &m_ptr;
        }

    private:

        COMType* m_ptr;

    };

}

#endif